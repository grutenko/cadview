#include "cv_object_global_props.h"
#include "../compat/litecad.h"
#include "cv_object.h"
#include "cv_object_prop.h"

#include <stdlib.h>

static void _destroy(cv_object_t *obj) {}

cv_variant_t _prop_get_regcode(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_version(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_msgtitle(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_msgtitle(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_helpfile(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_helpfile(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_dirdll(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_dirfonts(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_dirfonts(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_dirlng(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_dirlng(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_dirtpl(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_dirtpl(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_dircfg(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_dircfg(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_savecfg(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_savecfg(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_icon16(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_icon16(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_icon32(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_icon32(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_rulerbmp(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_rulerbmp(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_prnusebmp(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_prnusebmp(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_prnbmpfile(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_prnbmpfile(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_prnbtnras(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_prnbtnras(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_prnbtnsrif(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_prnbtnsrif(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_pntpixsize(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_pntpixsize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_getdelent(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_getdelent(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sbarheight(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_fileprogress(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_fileprogress(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_filedefext(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_filedefext(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_filelcd(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_filelcd(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_ordseq_auto(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_ordseq_auto(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_tabcmdwnd(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_tabcmdwnd(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_undomsg(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_undomsg(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_mincharsize(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_mincharsize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_panredqual(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_panredqual(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_entext(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_entext(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_dlgval(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_dlgval(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_str(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_str(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_int(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_float(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_handle(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_delkeyerase(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_delkeyerase(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_demotext(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_demotext(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_demosize(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_demosize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_democolor(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_democolor(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_pickboxsize(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_pickboxsize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_pickbyrect(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_pickbyrect(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_pickdrag(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_pickdrag(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_pickadd(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_pickadd(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_pickbylayer(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_pickbylayer(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_pickinpgon(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_pickinpgon(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_pickinpgonf(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_pickinpgonf(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_pickinimg(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_pickinimg(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_colorl1(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_colorl1(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_colorl2(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_colorl2(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_colorf(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_colorf(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_hatchfill(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_hatchfill(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_enablegrips(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_enablegrips(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_gripsize(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_gripsize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_gripcolorf(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_gripcolorf(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_gripcolorb(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_gripcolorb(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_gripentlim(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_gripentlim(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_sel_gripnum(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_sel_gripnum(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_osnap_mark(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_osnap_mark(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_osnap_aper(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_osnap_aper(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_osnap_marksize(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_osnap_marksize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_osnap_apersize(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_osnap_apersize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_osnap_markcolor(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_osnap_markcolor(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_nav_left(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_nav_left(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_nav_top(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_nav_top(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_nav_width(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_nav_width(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_nav_height(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_nav_height(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_ealen(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_ealen(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_eaw(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_eaw(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_jalen(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_jalen(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_jaw(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_jaw(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_acolor(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_acolor(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_numfont(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_numfont(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_numsize(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_numsize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_numcolor(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_numcolor(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_drawjarr(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_drawjarr(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_drawjline(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_drawjline(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_drawedot(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_drawedot(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_drawearr(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_drawearr(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_jl_drawenum(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_jl_drawenum(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_camera_count(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_camera_count(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_camera_i(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_camera_i(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_camera_name(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_camera_on(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_camera_time(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_camera_time(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_camera_width(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_camera_height(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_camera_bits(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_camera_bprow(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_ras_fill(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_ras_fill(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_ras_color(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_ras_color(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_ras_noprint(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

void _prop_set_ras_noprint(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

cv_variant_t _prop_get_tin_pt0(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_tin_pt1(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

cv_variant_t _prop_get_tin_tr(cv_object_t *obj, cv_object_prop_t *prop) { return (cv_variant_t){0}; }

static cv_object_prop_t _props[] = {CV_OBJECT_DEFINE_STRING_RO(LC_PROP_G_REGCODE, _prop_get_regcode),
                                    CV_OBJECT_DEFINE_STRING_RO(LC_PROP_G_VERSION, _prop_get_version),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_MSGTITLE, _prop_get_msgtitle, _prop_set_msgtitle),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_HELPFILE, _prop_get_helpfile, _prop_set_helpfile),
                                    CV_OBJECT_DEFINE_STRING_RO(LC_PROP_G_DIRDLL, _prop_get_dirdll),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_DIRFONTS, _prop_get_dirfonts, _prop_set_dirfonts),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_DIRLNG, _prop_get_dirlng, _prop_set_dirlng),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_DIRTPL, _prop_get_dirtpl, _prop_set_dirtpl),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_DIRCFG, _prop_get_dircfg, _prop_set_dircfg),
                                    CV_OBJECT_DEFINE_HANDLE(LC_PROP_G_ICON16, _prop_get_icon16, _prop_set_icon16),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_ICON16, _prop_get_icon16, _prop_set_icon16),
                                    CV_OBJECT_DEFINE_HANDLE(LC_PROP_G_ICON32, _prop_get_icon32, _prop_set_icon32),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_ICON32, _prop_get_icon32, _prop_set_icon32),
                                    CV_OBJECT_DEFINE_HANDLE(LC_PROP_G_RULERBMP, _prop_get_rulerbmp, _prop_set_rulerbmp),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_RULERBMP, _prop_get_rulerbmp, _prop_set_rulerbmp),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_PRNUSEBMP, _prop_get_prnusebmp, _prop_set_prnusebmp),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_PRNBMPFILE, _prop_get_prnbmpfile, _prop_set_prnbmpfile),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_PRNBTNRAS, _prop_get_prnbtnras, _prop_set_prnbtnras),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_PRNBTNSRIF, _prop_get_prnbtnsrif, _prop_set_prnbtnsrif),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_PNTPIXSIZE, _prop_get_pntpixsize, _prop_set_pntpixsize),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_GETDELENT, _prop_get_getdelent, _prop_set_getdelent),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_G_SBARHEIGHT, _prop_get_sbarheight),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_FILEPROGRESS, _prop_get_fileprogress, _prop_set_fileprogress),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_FILEDEFEXT, _prop_get_filedefext, _prop_set_filedefext),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_FILELCD, _prop_get_filelcd, _prop_set_filelcd),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_TABCMDWND, _prop_get_tabcmdwnd, _prop_set_tabcmdwnd),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_UNDOMSG, _prop_get_undomsg, _prop_set_undomsg),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_MINCHARSIZE, _prop_get_mincharsize, _prop_set_mincharsize),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_PANREDQUAL, _prop_get_panredqual, _prop_set_panredqual),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_ENTEXT, _prop_get_entext, _prop_set_entext),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_DLGVAL, _prop_get_dlgval, _prop_set_dlgval),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_STR, _prop_get_str, _prop_set_str),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_G_INT, _prop_get_int),
                                    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_G_FLOAT, _prop_get_float),
                                    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_G_HANDLE, _prop_get_handle),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_DELKEYERASE, _prop_get_delkeyerase, _prop_set_delkeyerase),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_DEMOTEXT, _prop_get_demotext, _prop_set_demotext),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_DEMOSIZE, _prop_get_demosize, _prop_set_demosize),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_DEMOCOLOR, _prop_get_democolor, _prop_set_democolor),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_SEL_PICKBOXSIZE, _prop_get_sel_pickboxsize, _prop_set_sel_pickboxsize),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_SEL_PICKBYRECT, _prop_get_sel_pickbyrect, _prop_set_sel_pickbyrect),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_SEL_PICKDRAG, _prop_get_sel_pickdrag, _prop_set_sel_pickdrag),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_SEL_PICKADD, _prop_get_sel_pickadd, _prop_set_sel_pickadd),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_SEL_PICKBYLAYER, _prop_get_sel_pickbylayer, _prop_set_sel_pickbylayer),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_SEL_PICKINPGON, _prop_get_sel_pickinpgon, _prop_set_sel_pickinpgon),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_SEL_PICKINPGONF, _prop_get_sel_pickinpgonf, _prop_set_sel_pickinpgonf),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_SEL_PICKINIMG, _prop_get_sel_pickinimg, _prop_set_sel_pickinimg),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_SEL_COLORL1, _prop_get_sel_colorl1, _prop_set_sel_colorl1),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_SEL_COLORL2, _prop_get_sel_colorl2, _prop_set_sel_colorl2),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_SEL_COLORF, _prop_get_sel_colorf, _prop_set_sel_colorf),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_SEL_HATCHFILL, _prop_get_sel_hatchfill, _prop_set_sel_hatchfill),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_SEL_ENABLEGRIPS, _prop_get_sel_enablegrips, _prop_set_sel_enablegrips),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_SEL_GRIPSIZE, _prop_get_sel_gripsize, _prop_set_sel_gripsize),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_SEL_GRIPCOLORF, _prop_get_sel_gripcolorf, _prop_set_sel_gripcolorf),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_SEL_GRIPCOLORB, _prop_get_sel_gripcolorb, _prop_set_sel_gripcolorb),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_SEL_GRIPENTLIM, _prop_get_sel_gripentlim, _prop_set_sel_gripentlim),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_SEL_GRIPNUM, _prop_get_sel_gripnum, _prop_set_sel_gripnum),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_OSNAP_MARK, _prop_get_osnap_mark, _prop_set_osnap_mark),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_OSNAP_APER, _prop_get_osnap_aper, _prop_set_osnap_aper),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_OSNAP_MARKSIZE, _prop_get_osnap_marksize, _prop_set_osnap_marksize),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_OSNAP_APERSIZE, _prop_get_osnap_apersize, _prop_set_osnap_apersize),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_OSNAP_MARKCOLOR, _prop_get_osnap_markcolor, _prop_set_osnap_markcolor),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_NAV_LEFT, _prop_get_nav_left, _prop_set_nav_left),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_NAV_TOP, _prop_get_nav_top, _prop_set_nav_top),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_NAV_WIDTH, _prop_get_nav_width, _prop_set_nav_width),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_NAV_HEIGHT, _prop_get_nav_height, _prop_set_nav_height),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_JL_EALEN, _prop_get_jl_ealen, _prop_set_jl_ealen),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_JL_EAW, _prop_get_jl_eaw, _prop_set_jl_eaw),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_JL_JALEN, _prop_get_jl_jalen, _prop_set_jl_jalen),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_JL_JAW, _prop_get_jl_jaw, _prop_set_jl_jaw),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_JL_ACOLOR, _prop_get_jl_acolor, _prop_set_jl_acolor),
                                    CV_OBJECT_DEFINE_STRING(LC_PROP_G_JL_NUMFONT, _prop_get_jl_numfont, _prop_set_jl_numfont),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_JL_NUMSIZE, _prop_get_jl_numsize, _prop_set_jl_numsize),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_JL_NUMCOLOR, _prop_get_jl_numcolor, _prop_set_jl_numcolor),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_JL_DRAWJARR, _prop_get_jl_drawjarr, _prop_set_jl_drawjarr),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_JL_DRAWJLINE, _prop_get_jl_drawjline, _prop_set_jl_drawjline),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_JL_DRAWEDOT, _prop_get_jl_drawedot, _prop_set_jl_drawedot),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_JL_DRAWEARR, _prop_get_jl_drawearr, _prop_set_jl_drawearr),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_JL_DRAWENUM, _prop_get_jl_drawenum, _prop_set_jl_drawenum),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_CAMERA_COUNT, _prop_get_camera_count, _prop_set_camera_count),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_CAMERA_I, _prop_get_camera_i, _prop_set_camera_i),
                                    CV_OBJECT_DEFINE_STRING_RO(LC_PROP_G_CAMERA_NAME, _prop_get_camera_name),
                                    CV_OBJECT_DEFINE_INT(LC_PROP_G_CAMERA_TIME, _prop_get_camera_time, _prop_set_camera_time),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_G_CAMERA_WIDTH, _prop_get_camera_width),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_G_CAMERA_HEIGHT, _prop_get_camera_height),
                                    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_G_CAMERA_BITS, _prop_get_camera_bits),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_G_CAMERA_BITS, _prop_get_camera_bits),
                                    CV_OBJECT_DEFINE_INT_RO(LC_PROP_G_CAMERA_BPROW, _prop_get_camera_bprow),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_RAS_FILL, _prop_get_ras_fill, _prop_set_ras_fill),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_RAS_COLOR, _prop_get_ras_color, _prop_set_ras_color),
                                    CV_OBJECT_DEFINE_BOOL(LC_PROP_G_RAS_NOPRINT, _prop_get_ras_noprint, _prop_set_ras_noprint),
                                    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_G_TIN_PT0, _prop_get_tin_pt0),
                                    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_G_TIN_PT1, _prop_get_tin_pt1),
                                    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_G_TIN_TR, _prop_get_tin_tr),
                                    CV_OBJECT_DEFINE_END()};
static cv_object_vtable_t _vtable = {.destroy = _destroy};

static struct {
  cv_object_t _obj;
  char *regcode;
  char *version;
  char *msgtitle;
  char *helpfile;
  char *dirdll;
  char *dirfonts;
  char *dirlng;
  char *dirtpl;
  char *dircfg;
  char *savecfg;
  char *icon16_filename;
  char *icon32_filename;
  uint8_t *icon16;
  uint8_t *icon32;
  size_t icon16_size;
  size_t icon32_size;
  char *rulerbmp_filename;
  uint8_t *rulerbmp;
  size_t rulerbmp_size;
  int prnusebmp;
  char *prnbmpfile;
  int prnbtnras;
  int prnbtnsrif;
  int pntpixsize;
  int getdelent;
  int64_t sbarheight;
  int fileprogress;
  char *filedefext;
  int filelcd;
  int ordseq_auto;
  int tabcmdwnd;
  int undomsg;
  int64_t mincharsize;
  int panredqual;
  int entext;
  char *dlgval;
  char *str;
  double float_;
  void *handle;
  int delkeyerase;
  char *demotext;
  int64_t demosize;
  int64_t democolor;
  int64_t sel_pickboxsize;
  int sel_pickbyrect;
  int sel_pickdrag;
  int sel_pickadd;
  int sel_pickbylayer;
  int sel_pickinpgon;
  int sel_pickinimg;
  int64_t sel_colorl1;
  int64_t sel_colorl2;
  int64_t sel_colorf;
  int hatchfill;
  int enablegrips;
  int64_t gripsize;
  int64_t gripcolorf;
  int64_t gripcolorb;
  int64_t gripentlim;
  int gripnum;
  int osnap_mark;
  int osnap_aper;
  int64_t osnap_marksize;
  int64_t osnap_apersize;
  int64_t osnap_markcolor;
  int64_t nav_left;
  int64_t nav_top;
  int64_t nav_width;
  int64_t nav_height;
  int64_t jl_ealen;
  int64_t jl_eaw;
  int64_t jl_jalen;
  int64_t jl_jaw;
  int64_t jl_acolor;
  char *jl_numfont;
  int64_t jl_numsize;
  int64_t jl_numcolor;
  int jl_drawjarr;
  int jl_drawjline;
  int jl_drawedot;
  int jl_drawearr;
  int jl_drawenum;
  int64_t camera_count;
  int64_t camera_i;
  char *camera_name;
  int camera_on;
  int64_t camera_time;
  int64_t camera_width;
  int64_t camera_height;
  int ras_fill;
  int ras_color;
  int ras_noprint;
} _global_props = {._obj = {.props = _props, .vtable = &_vtable}};

cv_object_t *cv_object_global_attrs_get_ptr() { return (cv_object_t *)&_global_props; }