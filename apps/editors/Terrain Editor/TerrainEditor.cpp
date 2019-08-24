#include "TerrainEditor.h"
#include <gsgeom/gssceneutil.h>

TerrainEditor::TerrainEditor (const int &w, const int &h) : gswin::gswindow (0, "Terraineditor", "Terrain Editor v0.1", 0, 0, 0, w, h)
{
	m_bLeftDown = false;
	m_bRightDown = false;

	RECT r;
	GetClientRect (getHandle (), &r);

	m_pKernel = new gs::gskernel;
	m_pKernel->init (getHandle (), r.right - r.left, r.bottom - r.top);

	m_pTopLevel = new gsgeom::gsscene;
	gsgeom::gscamera *c = new gsgeom::gscamera;
	c->setProjection (r.right - r.left, r.bottom - r.top, (float)(r.bottom - r.top)/(float)(r.right - r.left), 0.1f, 300.f);
	c->setView (gsgeom::gsvec3f (15, 10, 15), gsgeom::gsvec3f (0, 0, 0), gsgeom::gsvec3f (0, 1, 0));
	m_pTopLevel->m_Camera = c;
	{
		gsgeom::gseffect *e = new gsgeom::gseffect;
		e->setBlend (true);
		e->setBlendFunc (gsgeom::gseffect::BLEND_ONE, gsgeom::gseffect::BLEND_ONE_MINUS_SRC_ALPHA);
		e->setDepthTest (true);
		e->setDepthValue (1.f);
		e->setDepthFunc (gsgeom::gseffect::DEPTH_LEQUAL);
		m_pTopLevel->m_pEffect = e;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		m_pTopLevel->m_Geometry = gi;
	}

	m_pCurrentScene = TerrainConfig::get ()->m_pScene;
	m_pCurrentScene->m_Geometry = new gsgeom::gsgeometryinfo;
	m_pTopLevel->m_ChildNodes.add (m_pCurrentScene);

	//picking, should be updated every mouse move call
	m_pPicking = new gsgeom::gsscene;

	//geometry
	m_pPicking->m_Geometry = new gsgeom::gsgeometryinfo;
	m_pPicking->m_Geometry->m_vPoints.add (gsgeom::gsvec3f (-1, 0, -1));
	m_pPicking->m_Geometry->m_vPoints.add (gsgeom::gsvec3f (1, 0, -1));
	m_pPicking->m_Geometry->m_vPoints.add (gsgeom::gsvec3f (1, 0, 1));
	m_pPicking->m_Geometry->m_vPoints.add (gsgeom::gsvec3f (-1, 0, 1));
	m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
	m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
	m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
	m_pPicking->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
	m_pPicking->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 0));
	m_pPicking->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 0));
	m_pPicking->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (1, 1));
	m_pPicking->m_Geometry->m_vTexCoordinates.add (gsgeom::gsvec2f (0, 1));
	gsimage::gstga *t = new gsimage::gstga;
	t->load ("ring.tga");
	m_pPicking->m_Geometry->m_Textures.add (t);

	//index
	gsgeom::gsgeometryinfo::IndexType *it = new gsgeom::gsgeometryinfo::IndexType;
	it->indexType = gsgeom::gsgeometryinfo::GS_SQUARE;
	it->m_vIndices.add (0);
	it->m_vIndices.add (1);
	it->m_vIndices.add (2);
	it->m_vIndices.add (3);
	m_pPicking->m_Geometry->m_vIndices.add (it);

	//effects
	gsgeom::gseffect *pe = new gsgeom::gseffect;
	pe->setAlphaTest (true);
	pe->setAlphaFunc (gsgeom::gseffect::ALPHA_GREATER, 0.5f);
	m_pPicking->m_pEffect = pe;

	//add to toplevel scene
	m_pTopLevel->m_ChildNodes.add (m_pPicking);

	m_bSelected = false;
	m_bLower = false;
	m_bRaise = false;

	m_pKernel->addEvent (gs::gsevent (gs::GS_ADD_SCENE, m_pTopLevel));

	//do this last, in case anything within fails it won't break execution of the above code.
	ToolsWindow = new TileTabControl (WS_EX_OVERLAPPEDWINDOW, "TileTabControl", "Tools Window", WS_OVERLAPPEDWINDOW, 800, 0, 450, 600);
	ToolsWindow->show ();
}

TerrainEditor::~TerrainEditor ()
{
	delete m_pKernel;
}

void TerrainEditor::handle ()
{
	while (m_iRun == 1)
		gswin::gswindow::handle ();
}

void TerrainEditor::onClose ()
{
	m_iRun = 0;
	m_pKernel->addEvent (gs::gsevent (gs::GS_QUIT, NULL));
	m_pKernel->shutdown ();
}

void TerrainEditor::onCommand (void *wParam, void *lParam)
{
#ifdef WIN32
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;
#endif
}

void TerrainEditor::onKeyDown (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	switch (wp)
	{
	case 'A':
	case VK_LEFT:
		{
			m_pKernel->m_pRenderMutex->lock ();
			m_pTopLevel->m_Camera->moveLeft (-0.5f);
			m_pKernel->m_pRenderMutex->unlock ();
		}
		break;

	case 'D':
	case VK_RIGHT:
		{
			m_pKernel->m_pRenderMutex->lock ();
			m_pTopLevel->m_Camera->moveLeft (0.5f);
			m_pKernel->m_pRenderMutex->unlock ();
		}
		break;

	case 'W':
	case VK_UP:
		{
			m_pKernel->m_pRenderMutex->lock ();
			m_pTopLevel->m_Camera->moveForward (-0.5f);
			m_pKernel->m_pRenderMutex->unlock ();
		}
		break;

	case 'S':
	case VK_DOWN:
		{
			m_pKernel->m_pRenderMutex->lock ();
			m_pTopLevel->m_Camera->moveForward (0.5f);
			m_pKernel->m_pRenderMutex->unlock ();
		}
		break;
	}
}

void TerrainEditor::onDestroy ()
{
	m_iRun = 0;
	m_pKernel->addEvent (gs::gsevent (gs::GS_QUIT, NULL));
}

void TerrainEditor::onMouseMove (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	int x = LOWORD (lParam);
	int y = HIWORD (lParam);

	RECT r;
	GetClientRect (getHandle (), &r);

	float fx = (float)x;
	float fy = (float)((r.bottom - r.top) - y);
	gsgeom::gsray ray = m_pTopLevel->m_Camera->getPicked (fx, fy);

	if (m_bLower)
	{
		gsgeom::gsvec3f point = gscol::gscollision::RayIntersectPoint (ray, TerrainConfig::get ()->m_pScene);

		for (float r = 0; r < 1.f; r+=0.05f)
		{
			gsutil::gsarray <unsigned int> indices;
			gsgeom::gssceneutil::getRadiusPoints (TerrainConfig::get ()->m_pScene, r, point, indices);


			TerrainConfig::get ()->m_pScene->m_Scene.lock ();
			for (unsigned int x = 0; x < indices.getSize (); x++)
			{
				int index = indices[x];
				gsgeom::gsvec3f p = TerrainConfig::get ()->m_pScene->m_Geometry->m_vPoints[index];
				p[1] -= 0.001f;
				TerrainConfig::get ()->m_pScene->m_Geometry->m_vPoints[index] = p;
			}
			TerrainConfig::get ()->m_pScene->m_Scene.unlock ();
		}
	}
	else if (m_bRaise)
	{
		gsgeom::gsvec3f point = gscol::gscollision::RayIntersectPoint (ray, TerrainConfig::get ()->m_pScene);

		for (float r = 0; r < 1.f; r+=0.05f)
		{
			gsutil::gsarray <unsigned int> indices;
			gsgeom::gssceneutil::getRadiusPoints (TerrainConfig::get ()->m_pScene, r, point, indices);

			for (unsigned int x = 0; x < indices.getSize (); x++)
			{
				int index = indices[x];
				gsgeom::gsvec3f p = TerrainConfig::get ()->m_pScene->m_Geometry->m_vPoints[index];
				p[1] += 0.001f;
				TerrainConfig::get ()->m_pScene->m_Geometry->m_vPoints[index] = p;
			}
		}
	}

	if (m_bRightDown)
	{
		float difx = (float)(x - oldx)*0.05f;
		float dify = (float)(y - oldy)*0.05f;

		m_pKernel->m_pRenderMutex->lock ();
		gsgeom::gscamera *c = m_pTopLevel->m_Camera;

		//x direction
		c->pitch (dify);

		//y direction
		c->yaw (difx);

		m_pKernel->m_pRenderMutex->unlock ();
	}
	else if (gscol::gscollision::isRayIntersect (ray, TerrainConfig::get ()->m_pScene))
	{
		gsgeom::gsvec3f point = gscol::gscollision::RayIntersectPoint (ray, TerrainConfig::get ()->m_pScene);

		m_pPicking->m_Geometry->m_vPoints[0] = gsgeom::gsvec3f (point[0] - 0.25f, point[1] + 0.01f, point[2] - 0.25f);
		m_pPicking->m_Geometry->m_vPoints[1] = gsgeom::gsvec3f (point[0] + 0.25f, point[1] + 0.01f, point[2] - 0.25f);
		m_pPicking->m_Geometry->m_vPoints[2] = gsgeom::gsvec3f (point[0] + 0.25f, point[1] + 0.01f, point[2] + 0.25f);
		m_pPicking->m_Geometry->m_vPoints[3] = gsgeom::gsvec3f (point[0] - 0.25f, point[1] + 0.01f, point[2] + 0.25f);
	}
	else
	{
		m_pPicking->m_Geometry->m_vPoints[0] = gsgeom::gsvec3f (0, 0, 0);
		m_pPicking->m_Geometry->m_vPoints[1] = gsgeom::gsvec3f (0, 0, 0);
		m_pPicking->m_Geometry->m_vPoints[2] = gsgeom::gsvec3f (0, 0, 0);
		m_pPicking->m_Geometry->m_vPoints[3] = gsgeom::gsvec3f (0, 0, 0);
	}

	oldx = x;
	oldy = y;
}

void TerrainEditor::onMouseWheel (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	m_pKernel->m_pRenderMutex->lock ();

	gsgeom::gscamera *c = m_pTopLevel->m_Camera;
	short w = HIWORD (wp);

	float dx = -w/120.f;

	c->moveForward (dx*1.5f);

	m_pKernel->m_pRenderMutex->unlock ();
}

void TerrainEditor::onMouseLeftDown (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	int x = LOWORD (lParam);
	int y = HIWORD (lParam);

	float fx = (float)x;
	float fy = (float)(getHeight () - y) - 48.f;
	gsgeom::gsray r = m_pTopLevel->m_Camera->getPicked (fx, fy);

	if (TerrainConfig::get ()->m_bFlatten)
	{
		m_bLower = true;
	}
	else if (TerrainConfig::get ()->m_bRaise)
	{
		m_bRaise = true;
	}
}

void TerrainEditor::onMouseLeftUp (void *wParam, void *lParam)
{
	if (TerrainConfig::get ()->m_bFlatten)
	{
		m_bLower = false;
	}
	else if (TerrainConfig::get ()->m_bRaise)
	{
		m_bRaise = false;
	}
}

void TerrainEditor::onMouseMiddleDown (void *wParam, void *lParam)
{
}

void TerrainEditor::onMouseMiddleUp (void *wParam, void *lParam)
{
}

void TerrainEditor::onMouseRightDown (void *wParam, void *lParam)
{
	m_bRightDown = true;
}

void TerrainEditor::onMouseRightUp (void *wParam, void *lParam)
{
	m_bRightDown = false;
}
