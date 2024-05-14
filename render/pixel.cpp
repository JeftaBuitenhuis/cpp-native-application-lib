struct rgba_pixel{
    public:
        rgba_pixel(char r, char g, char b, char a) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }

    char r;
    char g;
    char b;
    char a;
};