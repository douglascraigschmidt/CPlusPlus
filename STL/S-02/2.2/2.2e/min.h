template <typename T>
T min (T p1, T p2) {
  if (p1 < p2)
    return p1;
  else
    return p2;
  // Could also use
  // return p1 < p2 ? p1 : p2;
}

template <typename T>
T min (T p1, T p2, T p3) {
  if (min (p1, p2) < p3) // notice this calls the function
    return min (p1, p2); // so does this line
  else
    return p3;
}
