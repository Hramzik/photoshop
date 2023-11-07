#ifndef FILTERS_CLASS_MASK_HPP_INCLUDED
#define FILTERS_CLASS_MASK_HPP_INCLUDED
//--------------------------------------------------


class Filter_Mask {

  public:

    Filter_Mask (int width, int height);
    ~Filter_Mask ();

    Filter_Mask (const Filter_Mask&) = delete;
    operator=   (const Filter_Mask&) = delete;

    //--------------------------------------------------

    //void resize (int width, int height);

    int get_width  () const;
    int get_height () const;

    bool get_value (int x, int y) const;
    void set_value (int x, int y, bool value);

    void fill (bool value);
    //void invert();

//--------------------------------------------------

  private:

    int width_;
    int height_;

    bool* buffer_;

    //--------------------------------------------------

    int get_buffer_index (int x, int y) const;
};


//--------------------------------------------------
#endif