#ifndef _gsmandelbrot_h_
#define _gsmandelbrot_h_

#include <gsgeom/gscolor.h>
#include <gsgeom/gsfractal.h>

#include <gsimage/gstexture.h>

#include <gsutil/gsstring.h>

namespace gsgeom
{
	class GS gsmandelbrot : public gsfractal
	{
	public:
		gsmandelbrot (const int &x, const int &y)
		{
			xmin = -2.1; ymin = -1.3; xmax = 1; ymax = 1.3; 
			m_pTexture = new gsimage::gstexture; m_pTexture->set (800, 600, 1);
		}

		~gsmandelbrot ()
		{
			delete m_pTexture;
		}

		void setSize (const int &w, const int &h)
		{
			m_pTexture->set (w, h, 1);
			generate ();
		}

	private:
		void generate ()
		{
			double intigralX = (xmax - xmin)/m_iWidth, intigralY = (ymax - ymin)/m_iHeight;
			double x = xmin;

			for (int s = 0; s < m_iWidth, s++)
			{
				double y = ymin;
				for (int z = 0; z < m_iHeight; z++)
				{
					double x1 = 0;
					double y1 = 0;
					int looper = 0;

					while (looper < 100 && sqrt (x1*x1 + y1*y1) < 2)
					{
						looper ++;
						double xx = x1*x1 - y1*y1 + x;
						y1 = 2*x1*y1 + y;
						x1 = xx;
					}

					double perc = looper/100.0;

					char val = (int)(perc*255);
					
					m_pTexture->setPixel (s, z, &val);
					y += intigralY;
				}
				x += intigralX;
			}
		}

		double xmin, ymin, xmax, ymax;

		int m_iWidth, m_iHeight;
		gsimage::gstexture *m_pTexture;
	};
};

#endif
