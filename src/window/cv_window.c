#include "cv_window.h"
#include "../compat/litecad.h"
#include "../object/cv_object.h"
#include "../object/cv_object_prop.h"

#include <stdlib.h>

static void _destroy(cv_object_t *obj) {}

cv_variant_t _get_id(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_id(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_width(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_height(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_frame_left(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_frame_top(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_frame_width(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_frame_height(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_hwnd(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_block(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_viewblock(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_drawing(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_hasfocus(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_pixelsize(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_pixelsize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_select(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_select(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_dtime(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_frozen(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_frozen(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_frozen_view(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_frozen_view(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_command(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_cmd(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_cmdent1(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_cmdend1(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_osnap(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_osnap(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_osnap_menu(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_osnap_menu(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_ptrack(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_ptrack(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_ptrack_angle(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_ptrack_angle(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_ptrack_angrel(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_ptrack_angrel(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_ptrack_dist(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_ptrack_dist(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_ptrack_dist_value(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_ptrack_dist_value(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_basept(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_basex(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_basey(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_ortho(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_ortho(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_bgimage(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_bgimage(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_bgimage_show(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_bgimage_show(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_tin(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_tin(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_hasfiletabs(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_numfiletabs(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_numdrw(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_ent(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_dropfiles(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_dropfiles(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_zoomwheel(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_zoomwheel(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rulers(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rulers(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_magnifier(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_magnifier(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_navigator(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_navigator(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_breakpoints(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_breakpoints(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_breakptnums(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_breakptnums(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_jumplines(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_jumplines(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_alphablend(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_alphablend(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_stdblkframe(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_stdblkframe(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_blkbasept(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_blkbasept(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_drawpaper(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_drawpaper(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_ltviewmin(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_ltviewmin(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_ltviewmax(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_ltviewmax(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_cursorarrow(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_cursorarrow(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_cursorsys(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_cursorsys(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_cursorhandle(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_cursorhandle(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_cursorcross(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_cursorcross(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_cursorsize(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_cursorsize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_cursorpbox(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_cursorpbox(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_pickboxsize(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_curx_pixel(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_curx(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_cury_pixel(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_cury(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_curlef(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_curbot(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_currig(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_curtop(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_coords(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_coords(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_xmin(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_ymin(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_xmax(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_ymax(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_xcen(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_ycen(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_dx(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_dy(cv_object_t *obj, cv_object_prop_t *prop) {}
cv_variant_t _get_gridsnap(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_gridsnap(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_gridshow(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_gridshow(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_griddx(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_griddx(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_griddy(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_griddy(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_gridx0(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_gridx0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_gridy0(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_gridy0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_gridboldx(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_gridboldx(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_gridboldy(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_gridboldy(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_gridcolor(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_gridcolor(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_griddotted(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_griddotted(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_gridcolor2(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_gridcolor2(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_griddotted2(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_griddotted2(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rsnap(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rsnap(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rsnapshow(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rsnapshow(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rsnaplef(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rsnaplef(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rsnapbot(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rsnapbot(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rsnaprig(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rsnaprig(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rsnaptop(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rsnaptop(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rsnapw(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rsnapw(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rsnaph(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rsnaph(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rsnapcolorm(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rsnapcolorm(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_rsnapcolorp(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_rsnapcolorp(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_panstep(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_panstep(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_panlw(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_panlw(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_panimage(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_panimage(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_panfill(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_panfill(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_panpixsz(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_panpixsz(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_meascolorpnt(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_meascolorpnt(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_meascolorline(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_meascolorline(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_measlinesize(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_measlinesize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_measfontsize(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_measfontsize(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_measfillarea(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_measfillarea(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_colorinfbg(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_colorinfbg(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_colorinfbord(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_colorinfbord(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_colorinftxt(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_colorinftxt(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_crects_edit(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_crects_edit(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_crects_visible(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_crects_visible(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_kbmove_enable(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_kbmove_enable(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_kbmove_dist(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_kbmove_dist(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_kbmove_angle(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_kbmove_angle(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_kbmove_scale(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_kbmove_scale(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_int0(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_int0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_int1(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_int1(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_int2(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_int2(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_int3(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_int3(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_int4(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_int4(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_int5(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_int5(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_int6(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_int6(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_int7(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_int7(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_int8(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_int8(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_int9(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_int9(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_float0(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_float0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_float1(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_float1(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_float2(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_float2(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_float3(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_float3(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_float4(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_float4(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_float5(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_float5(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_float6(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_float6(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_float7(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_float7(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_float8(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_float8(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_float9(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_float9(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_str0(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_str0(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_str1(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_str1(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_str2(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_str2(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_str3(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_str3(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_str4(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_str4(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_str5(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_str5(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_str6(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_str6(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_str7(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_str7(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_str8(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_str8(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}
cv_variant_t _get_str9(cv_object_t *obj, cv_object_prop_t *prop) {}
void _set_str9(cv_object_t *obj, cv_object_prop_t *prop, cv_variant_t value) {}

static cv_object_prop_t _props[] = {
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_ID, _get_id, _set_id),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_WIDTH, _get_width),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_HEIGHT, _get_height),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_FRAME_LEFT, _get_frame_left),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_FRAME_TOP, _get_frame_top),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_FRAME_WIDTH, _get_width),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_FRAME_HEIGHT, _get_frame_height),
    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_WND_HWND, _get_hwnd),
    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_WND_BLOCK, _get_block),
    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_WND_VIEWBLOCK, _get_block),
    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_WND_DRW, _get_drawing),
    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_WND_HASFOCUS, _get_hasfocus),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_PIXELSIZE, _get_pixelsize, _set_pixelsize),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_SELECT, _get_select, _set_select),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_DTIME, _get_dtime),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_FROZEN, _get_frozen, _set_frozen),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_FROZENVIEW, _get_frozen_view, _set_frozen_view),
    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_WND_COMMAND, _get_command),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_COMMAND, _get_command),
    CV_OBJECT_DEFINE_STRING_RO(LC_PROP_WND_COMMAND, _get_command),
    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_WND_CMD, _get_command),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_CMD, _get_command),
    CV_OBJECT_DEFINE_STRING_RO(LC_PROP_WND_CMD, _get_command),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_CMDENT1, _get_cmdent1, _set_cmdend1),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_OSNAP, _get_osnap, _set_osnap),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_OSNAP, _get_osnap, _set_osnap),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_OSNAPMENU, _get_osnap_menu, _set_osnap_menu),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_PTRACK, _get_ptrack, _set_ptrack),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_PTRACK_ANGLE, _get_ptrack_angle, _set_ptrack_angle),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_PTRACK_ANGREL, _get_ptrack_angrel, _set_ptrack_angrel),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_PTRACK_DIST, _get_ptrack_dist, _set_ptrack_dist),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_PTRACK_DIST, _get_ptrack_dist_value, _set_ptrack_dist_value),
    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_WND_BASEPT, _get_basept),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_BASEX, _get_basex),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_BASEY, _get_basey),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_ORTHO, _get_ortho, _set_ortho),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_BGIMAGE, _get_bgimage, _set_bgimage),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_BGIMAGE, _get_bgimage_show, _set_bgimage_show),
    CV_OBJECT_DEFINE_BOOL_RO(LC_PROP_WND_HASFILETABS, _get_hasfiletabs),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_NUMFILETABS, _get_numfiletabs),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_NUMDRW, _get_numdrw),
    CV_OBJECT_DEFINE_HANDLE_RO(LC_PROP_WND_ENT, _get_ent),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_DROPFILES, _get_dropfiles, _set_dropfiles),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_ZOOMWHEEL, _get_zoomwheel, _set_zoomwheel),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_RULERS, _get_rulers, _set_rulers),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_MAGNIFIER, _get_magnifier, _set_magnifier),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_NAVIGATOR, _get_navigator, _set_navigator),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_JUMPLINES, _get_jumplines, _set_jumplines),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_ALPHABLEND, _get_alphablend, _set_alphablend),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_STDBLKFRAME, _get_stdblkframe, _set_stdblkframe),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_BLKBASEPT, _get_blkbasept, _set_blkbasept),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_DRAWPAPER, _get_drawpaper, _set_drawpaper),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_LTVIEWMIN, _get_ltviewmin, _set_ltviewmin),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_LTVIEWMAX, _get_ltviewmax, _set_ltviewmax),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_CURSORARROW, _get_cursorarrow, _set_cursorarrow),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_CURSORSYS, _get_cursorsys, _set_cursorsys),
    CV_OBJECT_DEFINE_HANDLE(LC_PROP_WND_CURSORSYS, _get_cursorhandle, _set_cursorhandle),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_CURSORCROSS, _get_cursorcross, _set_cursorcross),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_CURSORSIZE, _get_cursorsize, _set_cursorsize),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_CURSORPBOX, _get_cursorpbox, _set_cursorpbox),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_PICKBOXSIZE, _get_pickboxsize),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_CURX, _get_curx_pixel),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_CURX, _get_curx),
    CV_OBJECT_DEFINE_INT_RO(LC_PROP_WND_CURY, _get_cury_pixel),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_CURY, _get_cury),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_CURLEF, _get_curlef),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_CURBOT, _get_curbot),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_CURRIG, _get_currig),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_CURTOP, _get_curtop),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_COORDS, _get_coords, _set_coords),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_XMIN, _get_xmin),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_YMIN, _get_ymin),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_XMAX, _get_xmax),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_YMAX, _get_ymax),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_XCEN, _get_xcen),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_YCEN, _get_ycen),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_DX, _get_dx),
    CV_OBJECT_DEFINE_FLOAT_RO(LC_PROP_WND_DY, _get_dy),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_GRIDSNAP, _get_gridsnap, _set_gridsnap),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_GRIDSHOW, _get_gridshow, _set_gridshow),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_GRIDDX, _get_griddx, _set_griddx),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_GRIDDY, _get_griddy, _set_griddy),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_GRIDX0, _get_gridx0, _set_gridx0),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_GRIDY0, _get_gridy0, _set_gridy0),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_GRIDBOLDX, _get_gridboldx, _set_gridboldx),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_GRIDBOLDY, _get_gridboldy, _set_gridboldy),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_GRIDCOLOR, _get_gridcolor, _set_gridcolor),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_GRIDDOTTED, _get_griddotted, _set_griddotted),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_GRIDCOLOR2, _get_gridcolor2, _set_gridcolor2),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_GRIDDOTTED2, _get_griddotted2, _set_griddotted2),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_RSNAP, _get_rsnap, _set_rsnap),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_RSNAPSHOW, _get_rsnapshow, _set_rsnapshow),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_RSNAPLEF, _get_rsnaplef, _set_rsnaplef),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_RSNAPBOT, _get_rsnapbot, _set_rsnapbot),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_RSNAPRIG, _get_rsnaprig, _set_rsnaprig),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_RSNAPTOP, _get_rsnaptop, _set_rsnaptop),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_RSNAPW, _get_rsnapw, _set_rsnapw),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_RSNAPH, _get_rsnaph, _set_rsnaph),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_RSNAPCOLORM, _get_rsnapcolorm, _set_rsnapcolorm),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_RSNAPCOLORP, _get_rsnapcolorp, _set_rsnapcolorp),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_PANSTEP, _get_panstep, _set_panstep),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_PANLW, _get_panlw, _set_panlw),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_PANIMAGE, _get_panimage, _set_panimage),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_PANFILL, _get_panfill, _set_panfill),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_PANPIXSZ, _get_panpixsz, _set_panpixsz),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_MEASCOLORPNT, _get_meascolorpnt, _set_meascolorpnt),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_MEASCOLORLINE, _get_meascolorline, _set_meascolorline),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_MEASLINESIZE, _get_measlinesize, _set_measlinesize),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_MEASFONTSIZE, _get_measfontsize, _set_measfontsize),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_MEASFILLAREA, _get_measfillarea, _set_measfillarea),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_COLORINFBG, _get_colorinfbg, _set_colorinfbg),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_COLORINFBORD, _get_colorinfbord, _set_colorinfbord),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_COLORINFTEXT, _get_colorinftxt, _set_colorinftxt),
    CV_OBJECT_DEFINE_BOOL(LC_PROP_WND_KBMOVE_ENABLE, _get_kbmove_enable, _set_kbmove_enable),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_KBMOVE_DIST, _get_kbmove_dist, _set_kbmove_dist),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_KBMOVE_ANGLE, _get_kbmove_angle, _set_kbmove_angle),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_KBMOVE_SCALE, _get_kbmove_scale, _set_kbmove_scale),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_INT0, _get_int0, _set_int0),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_INT1, _get_int1, _set_int1),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_INT2, _get_int2, _set_int2),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_INT3, _get_int3, _set_int3),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_INT4, _get_int4, _set_int4),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_INT5, _get_int5, _set_int5),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_INT6, _get_int6, _set_int6),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_INT7, _get_int7, _set_int7),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_INT8, _get_int8, _set_int8),
    CV_OBJECT_DEFINE_INT(LC_PROP_WND_INT9, _get_int9, _set_int9),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_FLOAT0, _get_float0, _set_float0),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_FLOAT1, _get_float1, _set_float1),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_FLOAT2, _get_float2, _set_float2),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_FLOAT3, _get_float3, _set_float3),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_FLOAT4, _get_float4, _set_float4),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_FLOAT5, _get_float5, _set_float5),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_FLOAT6, _get_float6, _set_float6),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_FLOAT7, _get_float7, _set_float7),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_FLOAT8, _get_float8, _set_float8),
    CV_OBJECT_DEFINE_FLOAT(LC_PROP_WND_FLOAT9, _get_float9, _set_float9),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_STR0, _get_str0, _set_str0),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_STR1, _get_str1, _set_str1),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_STR2, _get_str2, _set_str2),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_STR3, _get_str3, _set_str3),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_STR4, _get_str4, _set_str4),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_STR5, _get_str5, _set_str5),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_STR6, _get_str6, _set_str6),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_STR7, _get_str7, _set_str7),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_STR8, _get_str8, _set_str8),
    CV_OBJECT_DEFINE_STRING(LC_PROP_WND_STR9, _get_str9, _set_str9),
};

static cv_object_vtable_t _vtable = {.destroy = _destroy};

cv_window_t *cv_window_alloc() { return malloc(sizeof(cv_window_t)); }

#if defined(__linux__)
#include <gtk/gtk.h>
int cv_window_init_gtk3(cv_window_t *window, GtkWindow *parent) { return 0; }
#elif defined(_WIN32)
#include <windows.h>
int cv_window_win32(cv_window_t *window, HWND *parent) { return 0; }
#endif