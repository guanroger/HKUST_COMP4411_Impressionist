//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_file_chooser.H>		// FLTK file chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Text_Display.H>

#include "Impressionist.h"
#include "OriginalView.h"
#include "PaintView.h"

#include "ImpBrush.h"

class ImpressionistUI {
public:
	ImpressionistUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;
								
	PaintView*			m_paintView;
	OriginalView*		m_origView;

// for brush dialog
	Fl_Window*			m_brushDialog;
	Fl_Choice*			m_BrushTypeChoice;
	Fl_Choice*          m_StrokeDirChoice;

	Fl_Slider*			m_BrushSizeSlider;
	Fl_Slider*			m_BrushWidthSlider;
	Fl_Slider*			m_LineAngleSlider;
	Fl_Slider*			m_AlphaSlider;

	Fl_Button*          m_ClearCanvasButton;

// For color dialog
	Fl_Window*			m_ColorDialog;
	Fl_Slider*			m_RedSilder;
	Fl_Slider*			m_GreenSilder;
	Fl_Slider*			m_BlueSilder;

// Dissolve dialog
	Fl_Window			*m_DissolveDialog;
	Fl_Slider			*m_DissolveAlphaSilder;
	Fl_Button			*m_FileChoseButton;
	Fl_Button			*m_DissolveButton;
	//Fl_Text_Buffer		*m_buff;
	//Fl_Text_Display		*m_disp;

	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute

	int					getSize();
	void				setSize(int size);

	int					getBrushWidth();
	void				setBrushWidth(const int &width);

	int					getRotationAngle();
	void				setRotationAngle(const int& angle);

	float				getAlpha();
	void				setAlpha(const float &alpha);

	float				getRedScale() const;
	float				getGreenScale() const;
	float				getBlueScale() const;

	char				*getDissolveFileName() const;
	float				getDissolveAlpha() const;

private:
	ImpressionistDoc*	m_pDoc;		// pointer to document to communicate with the document

	// All attributes here
	int			m_nSize;
	int			m_nBrushWidth;
	int			m_nRotationAngle;
	float		m_nAlpha;
	float		m_nRedScale;
	float		m_nGreenScale;
	float		m_nBlueScale;
	char		*m_nDissolveFileName;
	float		m_nDissolveAlpha;


	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE+1];
	static Fl_Menu_Item		strokeDirMenu[NUM_STROKE_TYPE+1];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void cb_color(Fl_Menu_ *o, void *v);
	static void cb_undo(Fl_Menu_ *o, void *v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_dissolveDialog(Fl_Menu_ *o, void *v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void cb_swabView(Fl_Menu_ *o, void *v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
	static void	cb_sizeSlides(Fl_Widget* o, void* v);
	static void cb_strokeDir(Fl_Widget *o, void *v);
	static void cb_widthSlides(Fl_Widget *o, void *v);
	static void cb_rotationAngle(Fl_Widget *o, void *v);
	static void cb_alpha(Fl_Widget *o, void *v);
	static void cb_red(Fl_Widget *o, void *v);
	static void cb_green(Fl_Widget *o, void *v);
	static void cb_blue(Fl_Widget *o, void *v);
	static void cb_choseDissolveFile(Fl_Widget *o, void *v);
	static void cb_dissolveAlpha(Fl_Widget *o, void *v);
	static void cb_dissolve(Fl_Widget *o, void *v);
};

#endif
