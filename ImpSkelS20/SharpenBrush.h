#ifndef SHARPENBRUSH_H
#define SHARPENBRUSH_H

#include "SharpenBrush.h"

class SharpenBrush : public ImpBrush
{
public:
	SharpenBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	void SetColor(const Point source);
	char* BrushName(void);
};

#endif