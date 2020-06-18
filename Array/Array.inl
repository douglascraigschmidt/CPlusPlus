// Returns the length of the array.

template <typename T> INLINE size_t 
Array<T>::size () const
{
  return this->cur_size_;
}

template <typename T> INLINE bool
Array<T>::in_range (size_t index) const
{
  return index < this->cur_size_;
}

template <typename T> INLINE T &
Array<T>::operator[] (size_t index)
{
  return this->array_.get()[index];
}

template <typename T> INLINE const T &
Array<T>::operator[] (size_t index) const
{
  return this->array_[index];
}

// Get an iterator to the begniing of the array
template <typename T> INLINE typename Array<T>::iterator
Array<T>::begin ()
{
  return typename Array<T>::iterator (*this, 0);
}

// Get an iterator to the begniing of the array
template <typename T> INLINE const Const_Array_Iterator<T>
Array<T>::begin () const
{
  return typename Array<T>::const_iterator (*this, 0);
}

// Get an iterator pointing past the end of the array
template <typename T> INLINE typename Array<T>::iterator
Array<T>::end ()
{
  return typename Array<T>::iterator (*this, this->size ());
}

template <typename T> INLINE const Const_Array_Iterator<T>
Array<T>::end () const
{
  return typename Array<T>::const_iterator (*this, this->size ());
}

template <typename T> INLINE T &
Array_Iterator<T>::operator* ()
{
  return this->array_[this->pos_];
}

template <typename T> INLINE const T &
Array_Iterator<T>::operator* () const
{
  return this->array_[this->pos_];
}

template <typename T> INLINE Array_Iterator<T> &
Array_Iterator<T>::operator++ ()
{
  ++this->pos_;
  return *this;
}

template <typename T> INLINE Array_Iterator<T>
Array_Iterator<T>::operator++ (int)
{
  return Array_Iterator<T> (this->array_, pos_++);
}

template <typename T> INLINE Array_Iterator<T> &
Array_Iterator<T>::operator-- ()
{
  --this->pos_;
  return *this;
}

template <typename T> INLINE Array_Iterator<T>
Array_Iterator<T>::operator-- (int) 
{
  return Array_Iterator<T> (this->array_, pos_--);
}

template <typename T> INLINE bool
Array_Iterator<T>::operator== (const Array_Iterator<T> &rhs) const
{
  return &this->array_ == &rhs.array_ && this->pos_ == rhs.pos_;
}

template <typename T> INLINE bool
Array_Iterator<T>::operator!= (const Array_Iterator<T> &rhs) const
{
  return !(*this == rhs);
}

template <typename T> INLINE const T &
Const_Array_Iterator<T>::operator* () const
{
  return this->array_[this->pos_];
}

template <typename T> INLINE const Const_Array_Iterator<T> &
Const_Array_Iterator<T>::operator++ () const
{
  ++this->pos_;
  return *this;
}

template <typename T> INLINE Const_Array_Iterator<T> 
Const_Array_Iterator<T>::operator++ (int) const
{
  Const_Array_Iterator old (*this);
  ++(*this);
  return old;
}

template <typename T> INLINE const Const_Array_Iterator<T> &
Const_Array_Iterator<T>::operator-- () const
{
  --this->pos_;
  return *this;
}

template <typename T> INLINE Const_Array_Iterator<T> 
Const_Array_Iterator<T>::operator-- (int) const {
  Const_Array_Iterator old (*this);
  --(*this);
  return old;
}

template <typename T> INLINE bool
Const_Array_Iterator<T>::operator== (const Const_Array_Iterator<T> &rhs) const
{
  return &this->array_ == &rhs.array_ && this->pos_ == rhs.pos_;
}

template <typename T> INLINE bool
Const_Array_Iterator<T>::operator!= (const Const_Array_Iterator<T> &rhs) const
{
  return !(*this == rhs);
}
