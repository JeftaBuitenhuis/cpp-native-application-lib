class Window {
    public: 
        Window(int pos_lx, int pos_rx, int pos_ly, int pos_ry) {
            this->pos_lx = pos_lx;
            this->pos_ly = pos_ly;
            this->pos_rx = pos_rx;
            this->pos_ry = pos_ry;
        }

        int init() {
            
        }
    private:
        int pos_lx;
        int pos_rx;
        int pos_ly;
        int pos_ry;
}