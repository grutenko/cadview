#ifndef cv_platform_font_h
#define cv_platform_font_h

struct finded_font {
  char *path;
};

int find_font(const char *family, int style, int weight, struct finded_font *font);
void clean_finded_font(struct finded_font *font);

#endif