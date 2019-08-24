#include "CreatePanel.h"

CreatePanel::CreatePanel (data *pd, gswin::gswidget *parent) : gswin::gstabpanel (0, "STATIC", "Create", WS_GROUP|SS_OWNERDRAW|WS_CHILD|WS_VISIBLE, -1, parent)
{
	m_pData = pd;

	gswin::gsbox *a = new gswin::gsbox (gswin::gsVERTICAL, this);
	gswin::gsbox *b = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	b->add (new gswin::gsbutton (this, "|>", gsBUTTON_DEFPUSHBUTTON, BUTTON_TRIANGLE, 0, 0, 25, 25));
	b->add (new gswin::gsbutton (this, "[]", gsBUTTON_DEFPUSHBUTTON, BUTTON_SQUARE, 0, 0, 25, 25));
	b->add (new gswin::gsbutton (this, "<>", gsBUTTON_DEFPUSHBUTTON, BUTTON_CUBE, 0, 0, 25, 25));
	b->add (new gswin::gsbutton (this, "O", gsBUTTON_DEFPUSHBUTTON, BUTTON_SPHERE, 0, 0, 25, 25));
	a->add (b);
	a->add (35);
	gswin::gsbox *c = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	c->add (new gswin::gsdescription (this, "Scale:"), gswin::gsEXPAND);
	c->add (new gswin::gstextbox (this, "1", gswin::gsTEXT_LEFT, SCALE), gswin::gsEXPAND);
	a->add (c);
	a->add (10);
	a->add (new gswin::gsdescription (this, "Translate:"));
	gswin::gsbox *d = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	d->add (new gswin::gsdescription (this, "X:"), gswin::gsEXPAND);
	d->add (new gswin::gstextbox (this, "0", gswin::gsTEXT_LEFT, TRANSLATEX), gswin::gsEXPAND);
	a->add (d);
	gswin::gsbox *e = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	e->add (new gswin::gsdescription (this, "Y:"), gswin::gsEXPAND);
	e->add (new gswin::gstextbox (this, "0", gswin::gsTEXT_LEFT, TRANSLATEY), gswin::gsEXPAND);
	a->add (e);
	gswin::gsbox *f = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	f->add (new gswin::gsdescription (this, "Z:"), gswin::gsEXPAND);
	f->add (new gswin::gstextbox (this, "0", gswin::gsTEXT_LEFT, TRANSLATEZ), gswin::gsEXPAND);
	a->add (f);
	a->add (10);
	a->add (new gswin::gsdescription (this, "Rotation:"));
	gswin::gsbox *g = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	g->add (new gswin::gsdescription (this, "X:"), gswin::gsEXPAND);
	g->add (new gswin::gstextbox (this, "0", gswin::gsTEXT_LEFT, ROTATEX), gswin::gsEXPAND);
	a->add (g);
	gswin::gsbox *h = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	h->add (new gswin::gsdescription (this, "Y:"), gswin::gsEXPAND);
	h->add (new gswin::gstextbox (this, "0", gswin::gsTEXT_LEFT, ROTATEY), gswin::gsEXPAND);
	a->add (h);
	gswin::gsbox *i = new gswin::gsbox (gswin::gsHORIZONTAL, this);
	i->add (new gswin::gsdescription (this, "Y:"), gswin::gsEXPAND);
	i->add (new gswin::gstextbox (this, "0", gswin::gsTEXT_LEFT, ROTATEZ), gswin::gsEXPAND);
	a->add (i);
}

CreatePanel::~CreatePanel ()
{
}

void CreatePanel::onCommand (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;
	LPARAM lp = (LPARAM)lParam;

	if (HIWORD (wParam) == BN_CLICKED)
	{
		gsgeom::gsscene *s = new gsgeom::gsscene;
		gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
		s->m_Geometry = gi;

		float scale = (float)atof (dynamic_cast <gswin::gstextbox*> (find (SCALE))->getText ().str ());
		float rotx = (float)atof (dynamic_cast <gswin::gstextbox*> (find (ROTATEX))->getText ().str ());
		float roty = (float)atof (dynamic_cast <gswin::gstextbox*> (find (ROTATEY))->getText ().str ());
		float rotz = (float)atof (dynamic_cast <gswin::gstextbox*> (find (ROTATEZ))->getText ().str ());
		float transx = (float)atof (dynamic_cast <gswin::gstextbox*> (find (TRANSLATEX))->getText ().str ());
		float transy = (float)atof (dynamic_cast <gswin::gstextbox*> (find (TRANSLATEY))->getText ().str ());
		float transz = (float)atof (dynamic_cast <gswin::gstextbox*> (find (TRANSLATEZ))->getText ().str ());

		if ((HWND)lp == find (BUTTON_TRIANGLE)->getHandle ())
		{
			gsgeom::gsmatrix sc, rt, tr;
			sc.scale (gsgeom::gsvec3f (scale, scale, scale));
			rt.rot (rotx, roty, rotz);
			tr.translate (gsgeom::gsvec3f (transx, transy, transz));

			m_pData->m_pRootGraphics->m_Geometry->m_vPoints.add (tr*rt*sc*gsgeom::gsvec3f (0, 0, 0));
			m_pData->m_pRootGraphics->m_Geometry->m_vPoints.add (tr*rt*sc*gsgeom::gsvec3f (0, 0, 1));
			m_pData->m_pRootGraphics->m_Geometry->m_vPoints.add (tr*rt*sc*gsgeom::gsvec3f (1, 0, 0));

			m_pData->m_pRootGraphics->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
			m_pData->m_pRootGraphics->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
			m_pData->m_pRootGraphics->m_Geometry->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));

			gsgeom::gsgeometryinfo::IndexType *i = new gsgeom::gsgeometryinfo::IndexType;
			i->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
			i->m_vIndices.add (m_pData->m_pRootGraphics->m_Geometry->m_vPoints.getSize () - 3);
			i->m_vIndices.add (m_pData->m_pRootGraphics->m_Geometry->m_vPoints.getSize () - 2);
			i->m_vIndices.add (m_pData->m_pRootGraphics->m_Geometry->m_vPoints.getSize () - 1);
			m_pData->m_pRootGraphics->m_Geometry->m_vIndices.add (i);
			//gi->m_vIndices.add (i);
		}
		else if ((HWND)lp == find (BUTTON_SQUARE)->getHandle ())
		{
			gsgeom::gsmatrix m;
			m.scale (gsgeom::gsvec3f (scale, scale, scale));
			m.rotX (rotx);
			m.rotY (roty);
			m.rotZ (rotz);
			m.translate (gsgeom::gsvec3f (transx, transy, transz));

			gi->m_vPoints.add (m * gsgeom::gsvec3f (-1, 0, -1));
			gi->m_vPoints.add (m * gsgeom::gsvec3f (-1, 0, 1));
			gi->m_vPoints.add (m * gsgeom::gsvec3f (1, 0, -1));
			gi->m_vPoints.add (m * gsgeom::gsvec3f (1, 0, 1));

			gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
			gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
			gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
			gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));

			gsgeom::gsgeometryinfo::IndexType *i = new gsgeom::gsgeometryinfo::IndexType;
			i->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
			i->m_vIndices.add (0);
			i->m_vIndices.add (1);
			i->m_vIndices.add (2);
			i->m_vIndices.add (2);
			i->m_vIndices.add (3);
			i->m_vIndices.add (1);
			gi->m_vIndices.add (i);
		}

		if ((HWND)lp == find (BUTTON_CUBE)->getHandle ())
		{
			gi->m_vPoints.add (gsgeom::gsvec3f (-1, -1, -1));
			gi->m_vPoints.add (gsgeom::gsvec3f (-1, -1, 1));
			gi->m_vPoints.add (gsgeom::gsvec3f (-1, 1, -1));
			gi->m_vPoints.add (gsgeom::gsvec3f (-1, 1, 1));
			gi->m_vPoints.add (gsgeom::gsvec3f (1, -1, -1));
			gi->m_vPoints.add (gsgeom::gsvec3f (1, -1, 1));
			gi->m_vPoints.add (gsgeom::gsvec3f (1, 1, -1));
			gi->m_vPoints.add (gsgeom::gsvec3f (1, 1, 1));

			gsgeom::gsgeometryinfo::IndexType *i = new gsgeom::gsgeometryinfo::IndexType;
			i->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
			i->m_vIndices.add (0);
			i->m_vIndices.add (1);
			i->m_vIndices.add (3);
			i->m_vIndices.add (2);
			i->m_vIndices.add (3);
			i->m_vIndices.add (2);
			i->m_vIndices.add (4);
			i->m_vIndices.add (5);
			i->m_vIndices.add (4);
			i->m_vIndices.add (5);
			i->m_vIndices.add (6);
			i->m_vIndices.add (7);
			i->m_vIndices.add (6);
			i->m_vIndices.add (7);
			i->m_vIndices.add (0);
			i->m_vIndices.add (1);
			gi->m_vIndices.add (i);
		}

		if ((HWND)lp == find (BUTTON_SPHERE)->getHandle ())
		{
				float radius = 1.f;
				int count = 20;
				int levels = 20;

				//end points
				for (int x = 0; x < count; x++)
				{
					for (int y = 0; y < levels; y++)
					{
						float theta = (float)x*(float)M_PI/(float)count;
						float phi = (float)y*2*(float)M_PI/(float)levels;
						float sinTheta = sinf (theta);
						float sinPhi = sinf (phi);
						float cosTheta = cosf (theta);
						float cosPhi = cosf (phi);
						gi->m_vPoints.add (gsgeom::gsvec3f (radius*cosPhi*sinTheta, radius*sinPhi*sinTheta, radius*cosTheta));
					}
				}

				gsgeom::gsgeometryinfo::IndexType *it = new gsgeom::gsgeometryinfo::IndexType;
				it->indexType = gsgeom::gsgeometryinfo::GS_TRIANGLE;
				for (int x = 0; x < count; x++)
				{
					for (int y = 0; y < levels; y++)
					{
						it->m_vIndices.add (x*count + y);
						it->m_vIndices.add ((x + 1)*count + y);
						it->m_vIndices.add ((x + 1)*count + y + 1);

						it->m_vIndices.add ((x + 1)*count + y + 1);
						it->m_vIndices.add (x*count + y + 1);
						it->m_vIndices.add (x*count + y);
					}
				}
				gi->m_vIndices.add (it);

				for (unsigned int x = 0; x < gi->m_vPoints.getSize (); x++)
				{
					gsgeom::gsvec3f norm = gsgeom::gsvec3f (0, 0, 0) - gi->m_vPoints[x];
					norm.normalize ();

					gi->m_vNormals.add (norm);
					gi->m_vColors.add (gsgeom::gscolor (norm[0], norm[1], norm[2], 1));
				}
				s->m_Geometry = gi;
		}

		m_pData->m_pRootGraphics->m_ChildNodes.add (s);
	}
}
