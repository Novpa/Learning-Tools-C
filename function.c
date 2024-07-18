int increment(){
  static int count = 0;
  count++;
  return count;
}