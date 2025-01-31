#ifndef DSU_H
#define DSU_H

class DSU {
    public:
      DSU(int n);
      
      int find(int v);
      
      void merge(int x, int y);
};

#endif // DSU_H