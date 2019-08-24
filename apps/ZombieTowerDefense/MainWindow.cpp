#include "MainWindow.h"

MainWindow::MainWindow () : gswin::gswindow (0, "ZombieTowerDefense", "Tower Defense", gswin::gsWINDOW_OVERLAPPEDWINDOW, -1, 0, 0, 800, 600)
{
	m_pKernel = new gs::gskernel;
	m_pKernel->init (getHandle (), getAreaWidth (), getAreaHeight ());

	//camera
	m_pCamera = new gsgeom::gscamera;
	m_pCamera->setProjection (getAreaWidth (), getAreaHeight (), 45.f, 1.f, 300.f);
	m_pCamera->setView (gsgeom::gsvec3f (0.f, 10.f, 0.001f), gsgeom::gsvec3f (0.f, 0.f, 0.f), gsgeom::gsvec3f (0, 1, 0));

	//initial landscape:
	gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
	gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -10));
	gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 10));
	gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -10));
	gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 10));

	gi->m_vColors.add (gsgeom::gscolor (1, 0, 0));
	gi->m_vColors.add (gsgeom::gscolor (0, 1, 0));
	gi->m_vColors.add (gsgeom::gscolor (0, 0, 1));
	gi->m_vColors.add (gsgeom::gscolor (1, 1, 1));

	gsimage::gstexture *ground = new gsimage::gsbmp;
	ground->load ("");
	//gi->m_Textures.add (ground);

	gsgeom::gsgeometryinfo::IndexType *i = new gsgeom::gsgeometryinfo::IndexType;
	i->indexType = gsgeom::gsgeometryinfo::GS_SQUARE;
	i->m_vIndices.add (0);
	i->m_vIndices.add (1);
	i->m_vIndices.add (3);
	i->m_vIndices.add (2);
	gi->m_vIndices.add (i);

	gsgeom::gseffect *e = new gsgeom::gseffect;
	e->setBlend (true);
	e->setDepthTest (true);

	m_pScene = new gsgeom::gsscene;
	m_pScene->m_Camera = m_pCamera;
	m_pScene->m_Geometry = gi;
	m_pScene->m_pEffect = e;

	m_pUnits = new gsgeom::gsscene;

	m_pKernel->addEvent (gs::gsevent (gs::GS_ADD_SCENE, m_pScene));
}

MainWindow::~MainWindow ()
{
}

void MainWindow::onKeyDown (void *wParam, void *lParam)
{
	WPARAM wp = (WPARAM)wParam;

	switch (wp)
	{
	case 'W':
		{
			gsgeom::gsvec3f pos = m_pCamera->m_vPos;
			float dist = 10*tanf ((45.f*(M_PI/180.f))/2.f);
			if (-pos.getZ () + dist + 0.2f > 10.f)
			{
				float d = -pos.getZ () + dist;
				m_pCamera->moveUp (d - 10.f);
			}
			else
				m_pCamera->moveUp (0.2f);
		}
		break;

	case 'S':
		{
			gsgeom::gsvec3f pos = m_pCamera->m_vPos;
			float dist = 10*tanf ((45.f*(M_PI/180.f))/2.f);
			if (-pos.getZ () - dist - 0.2f < -10.f)
			{
				float d = -pos.getZ () - dist;
				m_pCamera->moveUp (d + 10.f);
			}
			else
				m_pCamera->moveUp (-0.2f);
		}
		break;

	case 'A':
		{
			gsgeom::gsvec3f pos = m_pCamera->m_vPos;
			float dist = 10*tanf ((45.f*(M_PI/180.f))/2.f);
			if (pos.getX () - dist - 0.2f < -10.f)
			{
				float d = pos.getX () - dist;
				m_pCamera->moveLeft (d + 10.f);
			}
			else
				m_pCamera->moveLeft (-0.2f);

			printf ("<%f %f %f> %f\n", pos.getX (), pos.getY (), pos.getZ (), dist);
		}
		break;

	case 'D':
		{
			gsgeom::gsvec3f pos = m_pCamera->m_vPos;
			float dist = 10*tanf ((45.f*(M_PI/180.f))/2.f);
			if (pos.getX () + dist + 0.2f > 10.f)
			{
				float d = pos.getX () + dist;
				m_pCamera->moveLeft (d - 10.f);
			}
			else
				m_pCamera->moveLeft (0.2f);

			printf ("<%f %f %f> %f\n", pos.getX (), pos.getY (), pos.getZ (), dist);
		}
		break;

	default:
		gswin::gswindow::onKeyDown (wParam, lParam);
	}
}
