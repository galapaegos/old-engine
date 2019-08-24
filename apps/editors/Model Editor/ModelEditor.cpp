#include "ModelEditor.h"

ModelEditor::ModelEditor () : gswin::gswindow (0, "Galapaegos3D", "Model Editor", gswin::gsWINDOW_OVERLAPPEDWINDOW, -1, 0, 0, 1200, 800)
{
	//initial
	m_pCurrentScene = NULL;
	m_bLeftButton = false;
	m_bMiddleButton = false;
	m_bRightButton = false;
	m_currentMode = CAMERA;
	m_scale = gsgeom::gsvec3f (1, 1, 1);

	//gswin::gsgroup *t = new gswin::gsgroup (this, 0, -1, 0, 0, getAreaWidth (), 30);
	gswin::gsbox *b = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	b->add (new gswin::gsbutton (this, "N", 1, PROJECT_NEW, 0, 0, 25, 25));
	b->add (new gswin::gsbutton (this, "O", 1, PROJECT_OPEN, 0, 0, 25, 25));
	b->add (new gswin::gsbutton (this, "S", 1, PROJECT_SAVE, 0, 0, 25, 25));
	b->add (25);
	b->add (new gswin::gsbutton (this, "C", 1, MANIPULATE_CAMERA, 0, 0, 25, 25));
	b->add (new gswin::gsbutton (this, "|\\", 1, MANIPULATE_SELECT, 0, 0, 25, 25));
	b->add (25);
	b->add (new gswin::gsbutton (this, "T", 1, TRANSFORM_TRANSLATE, 0, 0, 25, 25));
	b->add (new gswin::gsbutton (this, "R", 1, TRANSFORM_ROTATE, 0, 0, 25, 25));
	b->add (new gswin::gsbutton (this, "S", 1, TRANSFORM_SCALE, 0, 0, 25, 25));
	gswin::gsgroup *g = new gswin::gsgroup (this, 0, GL_PARENT, 0, b->getHeight () + 2, getAreaWidth () - 250, getAreaHeight () - b->getHeight () + 2);

	m_pKernel = new gs::gskernel;
	m_pKernel->init (g, g->getWidth (), g->getHeight ());

	m_pData = new data;
	m_pData->m_pCamera->setProjection (g->getWidth (), g->getHeight (), 45.f, 1.f, 300.f);
	m_pData->m_pCamera->setView (gsgeom::gsvec3f (0, 5, 5), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
	m_pKernel->addEvent (gs::gsevent (gs::GS_ADD_SCENE, m_pData->getRoot ()));

	m_pTabs = new gswin::gstabctl (this, 0, "ModelEditorTabCtrl", TCS_SINGLELINE|WS_CHILD|WS_VISIBLE, -1, getAreaWidth () - 250, b->getHeight () + 2, 250, getAreaHeight () - b->getHeight () + 2);
	CreatePanel *cp = new CreatePanel (m_pData, m_pTabs);
	cp->show ();
	EditPanel *ep = new EditPanel (m_pData, m_pTabs);
	ep->hide ();
	ShadingPanel *sp = new ShadingPanel (m_pData, m_pTabs);
	sp->hide ();
	RenderPanel *rp = new RenderPanel (m_pData, m_pTabs);
	rp->hide ();
	TerrainPanel *tp = new TerrainPanel (m_pData, m_pTabs);
	tp->hide ();

	show ();
}

ModelEditor::~ModelEditor ()
{
	delete m_pKernel;
	delete m_pData;
}

void ModelEditor::onNotify (void *wParam, void *lParam)
{
	m_pTabs->onNotify (wParam, lParam);
}

void ModelEditor::onClose ()
{
	m_pKernel->shutdown ();
	gswindow::onClose ();
}

void ModelEditor::onMouseLeftDown (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	switch (m_currentMode)
	{
	case CAMERA:
		{
			m_bLeftButton = true;
		}
		break;

	case SELECTION:
		{
			gswin::gsgroup *g = dynamic_cast <gswin::gsgroup*> (find (GL_PARENT));
			RECT r;
			GetClientRect (g->getHandle (), &r);

			POINT p;
			GetCursorPos (&p);
			ScreenToClient (g->getHandle (), &p);

			gsgeom::gsray ray = m_pData->m_pCamera->getPicked ((float)p.x, (float)((r.bottom - r.top) - p.y));
			if (gscol::gscollision::isRayIntersect (ray, m_pData->m_pRootGraphics))
			{
				printf ("gscol::gscollision::isRayIntersect\n");
				gsgeom::gsvec3i selected = gscol::gscollision::RayIntersectIndex (ray, m_pData->m_pRootGraphics);
				gsgeom::gsscene *s = gscol::gscollision::RayIntersectScene (ray, m_pData->m_pRootGraphics);
				gsgeom::gsgeometryinfo *g = s->m_Geometry;
				gsgeom::gsgeometryinfo *sg = m_pData->m_pSelection->m_Geometry;
				gsgeom::gsgeometryinfo::IndexType *si = m_pData->m_pSelection->m_Geometry->m_vIndices[0];

				//did we hit anything?
				if (selected[0] != -1 && selected[1] != -1 && selected[2] != -1)
				{
					printf ("selected[0] != -1 && selected[1] != -1 && selected[2] != -1\n");
					//we have a previous selection!
					if (si->m_vIndices.getSize () > 0)
					{
						printf ("si->m_vIndices.getSize () > 0\n");

						//compare to current
						//This will need to be expanded to support loops for multiple selections!
						if (selected[0] == m_selected[0] && selected[1] == m_selected[1] && selected[2] == m_selected[2])
						{
							printf ("same face\n");

							sg->m_vPoints.clear ();
							sg->m_vColors.clear ();
							si->m_vIndices.clear ();

							m_pCurrentScene = NULL;
							m_selected.set (-1, -1, -1);
						}
						else
						{
							printf ("different face! <%i %i %i> <%i %i %i>\n", selected[0], selected[1], selected[2],
								si->m_vIndices[0], si->m_vIndices[1], si->m_vIndices[2]);

							sg->m_vPoints.clear ();
							sg->m_vColors.clear ();
							si->m_vIndices.clear ();

							sg->m_vPoints.add (g->m_vPoints[selected[0]]);
							sg->m_vPoints.add (g->m_vPoints[selected[1]]);
							sg->m_vPoints.add (g->m_vPoints[selected[2]]);

							sg->m_vColors.add (gsgeom::gscolor (1, 1, 0));
							sg->m_vColors.add (gsgeom::gscolor (1, 1, 0));
							sg->m_vColors.add (gsgeom::gscolor (1, 1, 0));

							si->m_vIndices.add (0);
							si->m_vIndices.add (1);
							si->m_vIndices.add (1);
							si->m_vIndices.add (2);
							si->m_vIndices.add (2);
							si->m_vIndices.add (0);

							m_pCurrentScene = s;
							m_selected.set (selected[0], selected[1], selected[2]);
						}
					}
					else
					{
						printf ("si->m_vIndices.getSize () == 0\n");

						sg->m_vPoints.clear ();
						sg->m_vColors.clear ();
						si->m_vIndices.clear ();

						sg->m_vPoints.add (g->m_vPoints[selected[0]]);
						sg->m_vPoints.add (g->m_vPoints[selected[1]]);
						sg->m_vPoints.add (g->m_vPoints[selected[2]]);

						sg->m_vColors.add (gsgeom::gscolor (1, 1, 0));
						sg->m_vColors.add (gsgeom::gscolor (1, 1, 0));
						sg->m_vColors.add (gsgeom::gscolor (1, 1, 0));

						si->m_vIndices.add (0);
						si->m_vIndices.add (1);
						si->m_vIndices.add (1);
						si->m_vIndices.add (2);
						si->m_vIndices.add (2);
						si->m_vIndices.add (0);

						m_pCurrentScene = s;
						m_selected.set (selected[0], selected[1], selected[2]);
					}
				}
				else
				{
					printf ("selected[0] == -1 && selected[1] == -1 && selected[2] == -1\n");

					sg->m_vPoints.clear ();
					sg->m_vColors.clear ();
					si->m_vIndices.clear ();

					m_pCurrentScene = NULL;
					m_selected.set (-1, -1, -1);
				}
			}
			else
			{
				printf ("!gscol::gscollision::isRayIntersect\n");

				gsgeom::gsgeometryinfo *sg = m_pData->m_pSelection->m_Geometry;
				gsgeom::gsgeometryinfo::IndexType *si = m_pData->m_pSelection->m_Geometry->m_vIndices[0];

				sg->m_vPoints.clear ();
				sg->m_vColors.clear ();
				si->m_vIndices.clear ();

				m_pCurrentScene = NULL;
				m_selected.set (-1, -1, -1);
			}
		}
		break;

	case TRANSLATE:
		{
			m_bLeftButton = true;
		}
		break;

	case ROTATE:
		{
			m_bLeftButton = true;
		}
		break;

	case SCALE:
		{
			m_bLeftButton = true;
		}
		break;
	}

	int x = LOWORD (lParam);
	int y = HIWORD (lParam);
}

void ModelEditor::onMouseLeftUp (void *wParam, void *lParam)
{
	switch (m_currentMode)
	{
	case CAMERA:
		{
			m_bLeftButton = false;
		}
		break;

	case SELECTION:
		break;

	case TRANSLATE:
		{
			m_bLeftButton = false;
		}
		break;

	case ROTATE:
		{
			m_bLeftButton = false;
		}
		break;

	case SCALE:
		{
			m_bLeftButton = false;
			m_scale.set (1, 1, 1);
		}
		break;
	}
}

void ModelEditor::onMouseMiddleDown (void *wParam, void *lParam)
{
	switch (m_currentMode)
	{
	case CAMERA:
		{
			m_bMiddleButton = true;
		}
		break;

	case SELECTION:
		break;

	case TRANSLATE:
		{
			m_bMiddleButton = true;
		}
		break;

	case ROTATE:
		{
			m_bMiddleButton = true;
		}
		break;

	case SCALE:
		{
			m_bMiddleButton = true;
		}
		break;
	}
}

void ModelEditor::onMouseMiddleUp (void *wParam, void *lParam)
{
	switch (m_currentMode)
	{
	case CAMERA:
		{
			m_bMiddleButton = false;
		}
		break;

	case SELECTION:
		break;

	case TRANSLATE:
		{
			m_bMiddleButton = false;
		}
		break;

	case ROTATE:
		{
			m_bMiddleButton = false;
		}
		break;

	case SCALE:
		{
			m_bMiddleButton = false;
			m_scale.set (1, 1, 1);
		}
		break;
	}
}

void ModelEditor::onMouseRightDown (void *wParam, void *lParam)
{
	switch (m_currentMode)
	{
	case CAMERA:
		{
			m_bRightButton = true;
		}
		break;

	case SELECTION:
		break;

	case TRANSLATE:
		{
			m_bRightButton = true;
		}
		break;

	case ROTATE:
		{
			m_bRightButton = true;
		}
		break;

	case SCALE:
		{
			m_bRightButton = true;
		}
		break;
	}
}

void ModelEditor::onMouseRightUp (void *wParam, void *lParam)
{
	switch (m_currentMode)
	{
	case CAMERA:
		{
			m_bRightButton = false;
		}
		break;

	case SELECTION:
		break;

	case TRANSLATE:
		{
			m_bRightButton = false;
		}
		break;

	case ROTATE:
		{
			m_bRightButton = false;
		}
		break;

	case SCALE:
		{
			m_bRightButton = false;
			m_scale.set (1, 1, 1);
		}
		break;
	}
}

void ModelEditor::onMouseMove (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	int x = LOWORD (lParam);
	int y = HIWORD (lParam);

	switch (m_currentMode)
	{
	case CAMERA:
		{
			gsgeom::gscamera *c = m_pData->m_pCamera;
			if (wp == MK_LBUTTON && m_bLeftButton)
			{
				float difx = (float)(x - oldx)*0.05f;
				float dify = (float)(y - oldy)*0.05f;

				//x direction
				c->pitch (dify);

				//y direction
				c->yaw (difx);
			}
		}
		break;

	case SELECTION:
		{
		}
		break;

	case TRANSLATE:
		{
			if (m_bLeftButton)
			{
				gsgeom::gsscene *pGraphics = m_pData->m_pRootGraphics;
				gsgeom::gsscene *pSelected = m_pData->m_pSelection;

				float difx = (float)(x - oldx)*0.05f;

				gsgeom::gsmatrix m;
				m.translate (gsgeom::gsvec3f (difx, 0, 0));

				//pGraphics->m_Geometry->m_Xform = pGraphics->m_Geometry->m_Xform*m;
				//gsgeom::gsgeometryinfo::IndexType *si = m_pData->m_pSelection->m_Geometry->m_vIndices[0];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]];

				if (m_pCurrentScene)
				{
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]];

					pSelected->m_Geometry->m_vPoints[0] = m*pSelected->m_Geometry->m_vPoints[0];
					pSelected->m_Geometry->m_vPoints[1] = m*pSelected->m_Geometry->m_vPoints[1];
					pSelected->m_Geometry->m_vPoints[2] = m*pSelected->m_Geometry->m_vPoints[2];
				}
			}
			else if (m_bMiddleButton)
			{
				gsgeom::gsscene *pGraphics = m_pData->m_pRootGraphics;
				gsgeom::gsscene *pSelected = m_pData->m_pSelection;

				float difx = (float)(x - oldx)*0.05f;

				gsgeom::gsmatrix m;
				m.translate (gsgeom::gsvec3f (0, difx, 0));

				//gsgeom::gsgeometryinfo::IndexType *si = m_pData->m_pSelection->m_Geometry->m_vIndices[0];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]];

				if (m_pCurrentScene)
				{
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]];

					pSelected->m_Geometry->m_vPoints[0] = m*pSelected->m_Geometry->m_vPoints[0];
					pSelected->m_Geometry->m_vPoints[1] = m*pSelected->m_Geometry->m_vPoints[1];
					pSelected->m_Geometry->m_vPoints[2] = m*pSelected->m_Geometry->m_vPoints[2];
				}
			}
			else if (m_bRightButton)
			{
				gsgeom::gsscene *pGraphics = m_pData->m_pRootGraphics;
				gsgeom::gsscene *pSelected = m_pData->m_pSelection;

				float difx = (float)(x - oldx)*0.05f;

				gsgeom::gsmatrix m;
				m.translate (gsgeom::gsvec3f (0, 0, difx));

				//gsgeom::gsgeometryinfo::IndexType *si = m_pData->m_pSelection->m_Geometry->m_vIndices[0];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]];

				if (m_pCurrentScene)
				{
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]];

					pSelected->m_Geometry->m_vPoints[0] = m*pSelected->m_Geometry->m_vPoints[0];
					pSelected->m_Geometry->m_vPoints[1] = m*pSelected->m_Geometry->m_vPoints[1];
					pSelected->m_Geometry->m_vPoints[2] = m*pSelected->m_Geometry->m_vPoints[2];
				}
			}
		}
		break;

	case ROTATE:
		{
			if (m_bLeftButton)
			{
				gsgeom::gsscene *pGraphics = m_pData->m_pRootGraphics;
				gsgeom::gsscene *pSelected = m_pData->m_pSelection;

				float difx = (float)(x - oldx)*0.05f;

				gsgeom::gsmatrix m;
				m.rot (difx, 0, 0);

				//gsgeom::gsgeometryinfo::IndexType *si = m_pData->m_pSelection->m_Geometry->m_vIndices[0];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]];

				if (m_pCurrentScene)
				{
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]];

					pSelected->m_Geometry->m_vPoints[0] = m*pSelected->m_Geometry->m_vPoints[0];
					pSelected->m_Geometry->m_vPoints[1] = m*pSelected->m_Geometry->m_vPoints[1];
					pSelected->m_Geometry->m_vPoints[2] = m*pSelected->m_Geometry->m_vPoints[2];
				}
			}
			else if (m_bMiddleButton)
			{
				gsgeom::gsscene *pGraphics = m_pData->m_pRootGraphics;
				gsgeom::gsscene *pSelected = m_pData->m_pSelection;

				float difx = (float)(x - oldx)*0.05f;

				gsgeom::gsmatrix m;
				m.rot (0, difx, 0);

				//gsgeom::gsgeometryinfo::IndexType *si = m_pData->m_pSelection->m_Geometry->m_vIndices[0];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]];

				if (m_pCurrentScene)
				{
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]];

					pSelected->m_Geometry->m_vPoints[0] = m*pSelected->m_Geometry->m_vPoints[0];
					pSelected->m_Geometry->m_vPoints[1] = m*pSelected->m_Geometry->m_vPoints[1];
					pSelected->m_Geometry->m_vPoints[2] = m*pSelected->m_Geometry->m_vPoints[2];
				}
			}
			else if (m_bRightButton)
			{
				gsgeom::gsscene *pGraphics = m_pData->m_pRootGraphics;
				gsgeom::gsscene *pSelected = m_pData->m_pSelection;

				float difx = (float)(x - oldx)*0.05f;

				gsgeom::gsmatrix m;
				m.rot (0, 0, difx);

				//gsgeom::gsgeometryinfo::IndexType *si = m_pData->m_pSelection->m_Geometry->m_vIndices[0];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]];

				if (m_pCurrentScene)
				{
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]];

					pSelected->m_Geometry->m_vPoints[0] = m*pSelected->m_Geometry->m_vPoints[0];
					pSelected->m_Geometry->m_vPoints[1] = m*pSelected->m_Geometry->m_vPoints[1];
					pSelected->m_Geometry->m_vPoints[2] = m*pSelected->m_Geometry->m_vPoints[2];
				}
			}
		}
		break;

	case SCALE:
		{
			if (m_bLeftButton)
			{
				gsgeom::gsscene *pGraphics = m_pData->m_pRootGraphics;
				gsgeom::gsscene *pSelected = m_pData->m_pSelection;

				float difx = (float)(x - oldx)*0.05f;

				gsgeom::gsmatrix m;
				m.scale (gsgeom::gsvec3f (difx, 1, 1));

				//gsgeom::gsgeometryinfo::IndexType *si = m_pData->m_pSelection->m_Geometry->m_vIndices[0];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[0]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[2]];
				//pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]] = m*pGraphics->m_Geometry->m_vPoints[si->m_vIndices[4]];

				if (m_pCurrentScene)
				{
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[0]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[1]];
					m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]] = m*m_pCurrentScene->m_Geometry->m_vPoints[m_selected[2]];

					pSelected->m_Geometry->m_vPoints[0] = m*pSelected->m_Geometry->m_vPoints[0];
					pSelected->m_Geometry->m_vPoints[1] = m*pSelected->m_Geometry->m_vPoints[1];
					pSelected->m_Geometry->m_vPoints[2] = m*pSelected->m_Geometry->m_vPoints[2];
				}
			}
			else if (m_bMiddleButton)
			{
			}
			else if (m_bRightButton)
			{
			}
		}
		break;
	}

	oldx = x;
	oldy = y;
}

void ModelEditor::onMouseWheel (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	switch (m_currentMode)
	{
	case CAMERA:
		{
			gsgeom::gscamera *c = m_pData->m_pCamera;
			short dw = HIWORD (wp);

			float dx = -dw/120.f;

			c->moveForward (dx);
		}
		break;

	case SELECTION:
		break;
	}
}

void ModelEditor::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if (HIWORD (wp) == BN_CLICKED)
	{
		if ((HWND)lp == find (PROJECT_NEW)->getHandle ())
		{
			if (m_pData->m_pRootGraphics->m_ChildNodes.getSize () > 0)
			{
				if (MessageBox (NULL, "Continuing will clear all data, are you sure you wish to continue?", "New File?", MB_OK))
				{
					m_pData->m_pRootGraphics->m_Geometry->m_vPoints.clear ();
					m_pData->m_pRootGraphics->m_Geometry->m_vColors.clear ();
					m_pData->m_pRootGraphics->m_Geometry->m_vNormals.clear ();
					m_pData->m_pRootGraphics->m_Geometry->m_vTexCoordinates.clear ();
				}
				else
					return;
			}
		}

		if ((HWND)lp == find (PROJECT_OPEN)->getHandle ())
		{
			//gsutil::gsstring file = 
			//gs::gssceneloader::write (m_pData->m_pRootGraphics, "");
		}

		if ((HWND)lp == find (PROJECT_SAVE)->getHandle ())
		{
			//gsutil::gsstring file = 
			//gs::gssceneloader::write (m_pData->m_pRootGraphics, "");
		}

		if ((HWND)lp == find (MANIPULATE_CAMERA)->getHandle ())
		{
			m_currentMode = CAMERA;
		}

		if ((HWND)lp == find (MANIPULATE_SELECT)->getHandle ())
		{
			m_currentMode = SELECTION;
		}

		if ((HWND)lp == find (TRANSFORM_TRANSLATE)->getHandle ())
		{
			m_currentMode = TRANSLATE;
		}

		if ((HWND)lp == find (TRANSFORM_ROTATE)->getHandle ())
		{
			m_currentMode = ROTATE;
		}

		if ((HWND)lp == find (TRANSFORM_SCALE)->getHandle ())
		{
			m_currentMode = SCALE;
		}
	}
}
