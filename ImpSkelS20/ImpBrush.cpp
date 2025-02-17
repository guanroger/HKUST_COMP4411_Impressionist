//
// ImpBrush.cpp
//
// The implementation of virtual brush. All the other brushes inherit from it.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ImpBrush.h"
#include <math.h>

extern float rad2Deg(const float &);

// Static class member initializations
int			ImpBrush::c_nBrushCount	= 0;
ImpBrush**	ImpBrush::c_pBrushes	= NULL;

ImpBrush::ImpBrush(ImpressionistDoc*	pDoc, 
				   char*				name) :
					m_pDoc(pDoc), 
					m_pBrushName(name)
{
}

//---------------------------------------------------
// Return m_pDoc, which connects the UI and brushes
//---------------------------------------------------
ImpressionistDoc* ImpBrush::GetDocument(void)
{
	return m_pDoc;
}

//---------------------------------------------------
// Return the name of the current brush
//---------------------------------------------------
char* ImpBrush::BrushName(void)
{
	return m_pBrushName;
}

//----------------------------------------------------
// Set the color to paint with to the color at source,
// which is the coord at the original window to sample 
// the color from
//----------------------------------------------------
void ImpBrush::SetColor (const Point source)
{
	ImpressionistDoc* pDoc = GetDocument();

	GLubyte color[4];

	memcpy ( color, pDoc->GetOriginalPixel( source ), 3 );	// Copy the color from original source

	color[3] = static_cast<GLubyte>(255 * this->m_pDoc->getAlpha());	// Set the alpha value

	// Scaling
	float redScale		= pDoc->getRedScale();
	float greenScale	= pDoc->getGreenScale();
	float blueScale		= pDoc->getBlueScale();

	color[0] = static_cast<int>(color[0] * redScale		> ImpressionistDoc::MAX_COLOR_INDEX ? ImpressionistDoc::MAX_COLOR_INDEX : color[0] * redScale);
	color[1] = static_cast<int>(color[1] * greenScale	> ImpressionistDoc::MAX_COLOR_INDEX ? ImpressionistDoc::MAX_COLOR_INDEX : color[1] * greenScale);
	color[2] = static_cast<int>(color[2] * blueScale	> ImpressionistDoc::MAX_COLOR_INDEX ? ImpressionistDoc::MAX_COLOR_INDEX : color[2] * blueScale);

	glColor4ubv( color );
}

float Point::distFrom(const Point &otherPoint) {
	return sqrt(pow(otherPoint.x - this->x, 2) + pow(otherPoint.y - this->y, 2));
}

float Point::angleFrom(const Point &otherPoint) {

	int dx = otherPoint.x - this->x;
	int dy = otherPoint.y - this->y;

	if (dx == 0)	return 90.0;
	if (dy == 0)	return 0.0;

	return rad2Deg(atan2(dy, dx));
}
