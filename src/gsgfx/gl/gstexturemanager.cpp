#include <gsgfx/gl/gstexturemanager.h>

namespace gsgfx
{
	gstexturemanager::gstexturemanager ()
	{
	}

	gstexturemanager::~gstexturemanager ()
	{
		while (m_TexList.getSize ())
		{
			gsgltexture *tex = m_TexList[0];
			m_TexList.erase (0);
			delete tex;
		}
	}

	void gstexturemanager::setTexture (gsimage::gstexture *t, gsgeom::gstextureinfo *texInfo)
	{
		gsAssert (t && t->getWidth () > 0 && t->getHeight () > 0);

		gsgltexture *tex = new gsgltexture ();
		tex->m_pTexture = t;
		tex->m_pTexInfo = texInfo;

		m_TexList.add (tex);
	}

	void gstexturemanager::enableTexture (const unsigned int &stage, gsimage::gstexture *t)
	{
		glClientActiveTexture (GL_TEXTURE0 + stage);
		glActiveTexture (GL_TEXTURE0 + stage);

		gsAssert (t);

		gsgltexture *texture = findTexture (t);

		gsAssert (texture);

		texture->load ();
		texture->bind ();

		if (texture->m_pTexInfo)
			parseTextureEnvironment (texture->m_pTexInfo);
	}

	void gstexturemanager::disableTexture (const unsigned int &stage, gsimage::gstexture *t)
	{
		glClientActiveTexture (GL_TEXTURE0 + stage);
		glActiveTexture (GL_TEXTURE0 + stage);

		gsAssert (t);

		gsgltexture *texture = findTexture (t);

		gsAssert (texture);

		texture->unbind ();
	}

	void gstexturemanager::parseTextureEnvironment (gsgeom::gstextureinfo *texInfo)
	{
		for (unsigned int x = 0; x < texInfo->getSize (); x++)
		{
			int pname = 0, param = 0;
			texInfo->getVariable (x, &pname, &param);

			switch (pname)
			{
			case gsgeom::gstextureinfo::ENVIRONMENT_MODE:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::MODE_REPLACE:
						glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
						break;

					case gsgeom::gstextureinfo::MODE_MODULATE:
						glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
						break;

					case gsgeom::gstextureinfo::MODE_DECAL:
						glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
						break;

					case gsgeom::gstextureinfo::MODE_BLEND:
						glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
						break;

					case gsgeom::gstextureinfo::MODE_COMBINE:
						glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
						break;

					case gsgeom::gstextureinfo::MODE_ADD:
						glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ENVIRONMENT_COLOR:
				{
					//this takes an array, glTexEnviv or something akin to it
					gsgeom::gscolor c;
					texInfo->getVariable (x, &pname, &c);
					float col[4];
					col[0] = c.getR ();
					col[1] = c.getG ();
					col[2] = c.getG ();
					col[3] = c.getA ();
					glTexEnvfv (GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, col);
				}
				break;

			case gsgeom::gstextureinfo::ENVIRONMENT_COMBINE_RGB:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::MODE_REPLACE:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_REPLACE);
						break;

					case gsgeom::gstextureinfo::MODE_MODULATE:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_MODULATE);
						break;

					case gsgeom::gstextureinfo::MODE_ADD:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_ADD);
						break;

					case gsgeom::gstextureinfo::MODE_ADDSIGNED:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_ADD_SIGNED);
						break;

					case gsgeom::gstextureinfo::MODE_INTERPOLATE:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_INTERPOLATE);
						break;

					case gsgeom::gstextureinfo::MODE_SUBTRACT:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_SUBTRACT);
						break;

					case gsgeom::gstextureinfo::MODE_DOT3RGB:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_DOT3_RGB);
						break;

					case gsgeom::gstextureinfo::MODE_DOT3RGBA:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_DOT3_RGBA);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ENVIRONMENT_COMBINE_ALPHA:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::MODE_REPLACE:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_REPLACE);
						break;

					case gsgeom::gstextureinfo::MODE_MODULATE:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_MODULATE);
						break;

					case gsgeom::gstextureinfo::MODE_ADD:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_ADD);
						break;

					case gsgeom::gstextureinfo::MODE_ADDSIGNED:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_ADD_SIGNED);
						break;

					case gsgeom::gstextureinfo::MODE_INTERPOLATE:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_INTERPOLATE);
						break;

					case gsgeom::gstextureinfo::MODE_SUBTRACT:
						glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_SUBTRACT);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_SOURCE0_RGB:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_TEXTURE:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE0:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE0);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE1:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE1);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE2:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE2);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE3:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE3);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE4:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE4);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE5:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE5);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE6:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE6);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE7:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_TEXTURE7);
						break;

					case gsgeom::gstextureinfo::ARG_PRIMARY_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_PRIMARY_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_PREVIOUS:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_PREVIOUS);
						break;

					case gsgeom::gstextureinfo::ARG_CONSTANT:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_RGB, GL_CONSTANT);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_SOURCE1_RGB:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_TEXTURE:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE0:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE0);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE1:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE1);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE2:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE2);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE3:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE3);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE4:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE4);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE5:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE5);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE6:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE6);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE7:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_TEXTURE7);
						break;

					case gsgeom::gstextureinfo::ARG_PRIMARY_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_PRIMARY_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_PREVIOUS:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_PREVIOUS);
						break;

					case gsgeom::gstextureinfo::ARG_CONSTANT:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_RGB, GL_CONSTANT);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_SOURCE2_RGB:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_TEXTURE:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_TEXTURE);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE0:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_TEXTURE0);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE1:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_TEXTURE1);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE2:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_TEXTURE2);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE3:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_TEXTURE3);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE4:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_TEXTURE4);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE5:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_TEXTURE5);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE6:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_TEXTURE6);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE7:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_TEXTURE7);
						break;

					case gsgeom::gstextureinfo::ARG_PRIMARY_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_PRIMARY_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_PREVIOUS:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_PREVIOUS);
						break;

					case gsgeom::gstextureinfo::ARG_CONSTANT:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_RGB, GL_CONSTANT);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_SOURCE0_ALPHA:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_TEXTURE:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_TEXTURE);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE0:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_TEXTURE0);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE1:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_TEXTURE1);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE2:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_TEXTURE2);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE3:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_TEXTURE3);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE4:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_TEXTURE4);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE5:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_TEXTURE5);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE6:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_TEXTURE6);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE7:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_TEXTURE7);
						break;

					case gsgeom::gstextureinfo::ARG_PRIMARY_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_PRIMARY_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_PREVIOUS:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_PREVIOUS);
						break;

					case gsgeom::gstextureinfo::ARG_CONSTANT:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE0_ALPHA, GL_CONSTANT);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_SOURCE1_ALPHA:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_TEXTURE:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_TEXTURE);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE0:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_TEXTURE0);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE1:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_TEXTURE1);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE2:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_TEXTURE2);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE3:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_TEXTURE3);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE4:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_TEXTURE4);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE5:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_TEXTURE5);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE6:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_TEXTURE6);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE7:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_TEXTURE7);
						break;

					case gsgeom::gstextureinfo::ARG_PRIMARY_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_PRIMARY_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_PREVIOUS:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_PREVIOUS);
						break;

					case gsgeom::gstextureinfo::ARG_CONSTANT:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE1_ALPHA, GL_CONSTANT);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_SOURCE2_ALPHA:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_TEXTURE:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_TEXTURE);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE0:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_TEXTURE0);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE1:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_TEXTURE1);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE2:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_TEXTURE2);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE3:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_TEXTURE3);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE4:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_TEXTURE4);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE5:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_TEXTURE5);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE6:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_TEXTURE6);
						break;

					case gsgeom::gstextureinfo::ARG_TEXTURE7:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_TEXTURE7);
						break;

					case gsgeom::gstextureinfo::ARG_PRIMARY_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_PRIMARY_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_PREVIOUS:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_PREVIOUS);
						break;

					case gsgeom::gstextureinfo::ARG_CONSTANT:
						glTexEnvi (GL_TEXTURE_ENV, GL_SOURCE2_ALPHA, GL_CONSTANT);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_OPERAND0_RGB:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_SRC_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_ONE_MINUS_SRC_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_ONE_MINUS_SRC_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_ALPHA);
						break;

					case gsgeom::gstextureinfo::ARG_ONE_MINUS_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_OPERAND1_RGB:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_SRC_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_SRC_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_ONE_MINUS_SRC_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_ONE_MINUS_SRC_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_SRC_ALPHA);
						break;

					case gsgeom::gstextureinfo::ARG_ONE_MINUS_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_OPERAND2_RGB:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_SRC_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND2_RGB, GL_SRC_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_ONE_MINUS_SRC_COLOR:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND2_RGB, GL_ONE_MINUS_SRC_COLOR);
						break;

					case gsgeom::gstextureinfo::ARG_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND2_RGB, GL_SRC_ALPHA);
						break;

					case gsgeom::gstextureinfo::ARG_ONE_MINUS_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND2_RGB, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_OPERAND0_ALPHA:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_ALPHA, GL_SRC_ALPHA);
						break;

					case gsgeom::gstextureinfo::ARG_ONE_MINUS_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_OPERAND1_ALPHA:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND1_ALPHA, GL_SRC_ALPHA);
						break;

					case gsgeom::gstextureinfo::ARG_ONE_MINUS_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND1_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_OPERAND2_ALPHA:
				{
					switch (param)
					{
					case gsgeom::gstextureinfo::ARG_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND2_ALPHA, GL_SRC_ALPHA);
						break;

					case gsgeom::gstextureinfo::ARG_ONE_MINUS_SRC_ALPHA:
						glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND2_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						break;
					}
				}
				break;

			case gsgeom::gstextureinfo::ARG_RGB_SCALE:
				{
					float scale;
					texInfo->getVariable (x, &param, &scale);
					glTexEnvf (GL_TEXTURE_ENV, GL_RGB_SCALE, scale);
				}
				break;
				
			case gsgeom::gstextureinfo::ARG_ALPHA_SCALE:
				{
					float scale;
					texInfo->getVariable (x, &param, &scale);
					glTexEnvf (GL_TEXTURE_ENV, GL_ALPHA_SCALE, scale);
				}
				break;
			}
		}
	}

	void gstexturemanager::clear ()
	{
	}

	gsgfx::gsgltexture *gstexturemanager::findTexture (gsimage::gstexture *t)
	{
		for (unsigned int x = 0; x < m_TexList.getSize (); x++)
		{
			if (m_TexList[x]->m_pTexture = t)
				return m_TexList[x];
		}

		//couldn't find the texture involved!
		return NULL;
	}
};
