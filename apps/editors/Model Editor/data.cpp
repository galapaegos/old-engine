#include "data.h"

data::data ()
{
	//Root node
	m_pRoot = new gsgeom::gsscene;
	m_pRoot->m_strName = "Root";
	m_pRoot->m_Camera = new gsgeom::gscamera;
	m_pRoot->m_Geometry = new gsgeom::gsgeometryinfo;

	//Root effects
	gsgeom::gseffect *effect = new gsgeom::gseffect;
	effect->setBlend (true);
	effect->setBlendFunc (gsgeom::gseffect::BLEND_ONE, gsgeom::gseffect::BLEND_ONE_MINUS_SRC_ALPHA);
	effect->setDepthTest (true);
	effect->setDepthValue (1.f);
	effect->setDepthFunc (gsgeom::gseffect::DEPTH_LEQUAL);
	m_pRoot->m_pEffect = effect;

	//Selection effects
	gsgeom::gseffect *selEffect = new gsgeom::gseffect;
	selEffect->setLineSettings (true);
	selEffect->setLineWidth (2.f);

	//Selection Node
	m_pSelection = new gsgeom::gsscene;
	m_pSelection->m_Geometry = new gsgeom::gsgeometryinfo;
	m_pSelection->m_Geometry->m_vIndices.add (new gsgeom::gsgeometryinfo::IndexType);
	m_pSelection->m_Geometry->m_vIndices[0]->indexType = gsgeom::gsgeometryinfo::GS_LINE;
	m_pSelection->m_strName = "Selection";
	m_pSelection->m_pEffect = selEffect;

	//Root Graphics Node
	m_pRootGraphics = new gsgeom::gsscene;
	m_pRootGraphics->m_Geometry = new gsgeom::gsgeometryinfo;
	m_pRootGraphics->m_strName = "Root Graphics";

	//Root Menu Node
	m_pRootMenu = new gsgeom::gsscene;
	m_pRootMenu->m_Geometry = new gsgeom::gsgeometryinfo;
	m_pRootMenu->m_strName = "Root Menu";

	//pointer to the camera
	m_pCamera = m_pRoot->m_Camera;

	//Grid Node
	gsgeom::gsscene *grid = new gsgeom::gsscene;
	grid->m_strName = "grid";
	grid->m_RenderTarget = gsgeom::gsscene::RENDER_NORMAL;
	gsgeom::gsgeometryinfo *gi = new gsgeom::gsgeometryinfo;
	{
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-9, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-9, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-8, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-8, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-7, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-7, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-6, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-6, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-5, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-5, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-4, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-4, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-3, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-3, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-2, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-2, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-1, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-1, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (0, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (1, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (1, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (2, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (2, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (3, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (4, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (4, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (5, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (5, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (6, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (6, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (7, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (7, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (8, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (8, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (9, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (9, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 10));

		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -10));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -9));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -9));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -8));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -8));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -7));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -7));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -6));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -6));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -5));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -5));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -4));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -4));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -3));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -3));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -2));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -2));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, -1));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, -1));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 0));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 1));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 1));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 2));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 2));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 3));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 3));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 4));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 4));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 5));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 5));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 6));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 6));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 7));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 7));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 8));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 8));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 9));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 9));
		gi->m_vPoints.add (gsgeom::gsvec3f (-10, 0, 10));
		gi->m_vPoints.add (gsgeom::gsvec3f (10, 0, 10));

		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));
		gi->m_vColors.add (gsgeom::gscolor (1, 1, 1, 1));

		gsgeom::gsgeometryinfo::IndexType *i = new gsgeom::gsgeometryinfo::IndexType;
		i->indexType = gsgeom::gsgeometryinfo::GS_LINE;
		i->m_vIndices.add (0); i->m_vIndices.add (1);
		i->m_vIndices.add (2); i->m_vIndices.add (3);
		i->m_vIndices.add (4); i->m_vIndices.add (5);
		i->m_vIndices.add (6); i->m_vIndices.add (7);
		i->m_vIndices.add (8); i->m_vIndices.add (9);
		i->m_vIndices.add (10); i->m_vIndices.add (11);
		i->m_vIndices.add (12); i->m_vIndices.add (13);
		i->m_vIndices.add (14); i->m_vIndices.add (15);
		i->m_vIndices.add (16); i->m_vIndices.add (17);
		i->m_vIndices.add (18); i->m_vIndices.add (19);
		i->m_vIndices.add (20); i->m_vIndices.add (21);
		i->m_vIndices.add (22); i->m_vIndices.add (23);
		i->m_vIndices.add (24); i->m_vIndices.add (25);
		i->m_vIndices.add (26); i->m_vIndices.add (27);
		i->m_vIndices.add (28); i->m_vIndices.add (29);
		i->m_vIndices.add (30); i->m_vIndices.add (31);
		i->m_vIndices.add (32); i->m_vIndices.add (33);
		i->m_vIndices.add (34); i->m_vIndices.add (35);
		i->m_vIndices.add (36); i->m_vIndices.add (37);
		i->m_vIndices.add (38); i->m_vIndices.add (39);
		i->m_vIndices.add (40); i->m_vIndices.add (41);
		i->m_vIndices.add (42); i->m_vIndices.add (43);
		i->m_vIndices.add (44); i->m_vIndices.add (45);
		i->m_vIndices.add (46); i->m_vIndices.add (47);
		i->m_vIndices.add (48); i->m_vIndices.add (49);
		i->m_vIndices.add (50); i->m_vIndices.add (51);
		i->m_vIndices.add (52); i->m_vIndices.add (53);
		i->m_vIndices.add (54); i->m_vIndices.add (55);
		i->m_vIndices.add (56); i->m_vIndices.add (57);
		i->m_vIndices.add (58); i->m_vIndices.add (59);
		i->m_vIndices.add (60); i->m_vIndices.add (61);
		i->m_vIndices.add (62); i->m_vIndices.add (63);
		i->m_vIndices.add (64); i->m_vIndices.add (65);
		i->m_vIndices.add (66); i->m_vIndices.add (67);
		i->m_vIndices.add (68); i->m_vIndices.add (69);
		i->m_vIndices.add (70); i->m_vIndices.add (71);
		i->m_vIndices.add (72); i->m_vIndices.add (73);
		i->m_vIndices.add (74); i->m_vIndices.add (75);
		i->m_vIndices.add (76); i->m_vIndices.add (77);
		i->m_vIndices.add (78); i->m_vIndices.add (79);
		i->m_vIndices.add (80); i->m_vIndices.add (81);
		i->m_vIndices.add (82); i->m_vIndices.add (83);
		i->m_vIndices.add (84); i->m_vIndices.add (85);
		i->m_vIndices.add (86); i->m_vIndices.add (87);
		gi->m_vIndices.add (i);
	}
	grid->m_Geometry = gi;

	//adding children
	m_pRoot->m_ChildNodes.add (grid);
	m_pRoot->m_ChildNodes.add (m_pRootGraphics);
	m_pRoot->m_ChildNodes.add (m_pSelection);

	//add last so its rendered last
	m_pRoot->m_ChildNodes.add (m_pRootMenu);
}

data::~data ()
{
	cleanup ();
}

void data::cleanup ()
{

}

void data::lock ()
{
	m_pRoot->m_Scene.lock ();
}

void data::unlock ()
{
	m_pRoot->m_Scene.unlock ();
}
