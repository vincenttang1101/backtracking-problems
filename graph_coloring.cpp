#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Số đỉnh của đồ thị
#define numOfVertices 4

// 0 - Green, 1 - Blue
char colors[][30] = {"Green", "Blue"};
int color_used = 2;
int colorCount;

//Các kết nối trong đồ thị
int graph[numOfVertices][numOfVertices] = {{0, 1, 0, 1},
                                           {1, 0, 1, 0},
                                           {0, 1, 0, 1},
                                           {1, 0, 1, 0}};

//Đỉnh
typedef struct{
    char name;
    bool colored;
    int color;
} Vertex;

//Danh sách đỉnh
Vertex *vertexArray[numOfVertices];

//Hàm kiểm tra xem một đỉnh có bất kỳ đỉnh láng giềng chưa được tô màu nào hay không
int hasUncoloredNeighbours(int idx){
  for(int i=0;i<numOfVertices; i++){
    if(graph[idx][i] == 1 && vertexArray[i]->colored == false)
      return i;
  }
  return -1;
}

//Hàm kiểm tra xem có thể tô màu với màu [colorIndex] không
bool canColorWith(int colorIndex, int vertex) {
    Vertex *neighborVertex;
    for(int i=0; i<numOfVertices; i++){
      //Bỏ qua nếu hai đỉnh không kết nối
      if(graph[vertex][i] == 0) continue;

      neighborVertex = vertexArray[i];
      if(neighborVertex->colored && neighborVertex->color == colorIndex)
          return  false;
    }

    return true;
}

//Hàm tô màu cho đỉnh
bool setColors(int idx){
  int colorIndex, unColoredIdx;

    //Bước 1
    for (colorIndex=0; colorIndex<color_used; colorIndex++){
      // Bước 1.1 : Kiểm tra tính hợp lệ
      if(!canColorWith(colorIndex, idx)) continue; 

      //Bước 1.2 : Tô màu
      vertexArray[idx]->color =  colorIndex;
      vertexArray[idx]->colored = true;
      colorCount++;

      //Bước 1.3 : Tất cả các đỉnh đã được tô màu?
      if(colorCount == numOfVertices ) //Trường hợp cơ sở
          return true;

      //Bước 1.4 : Tìm đỉnh chưa được tô màu kế tiếp
      while((unColoredIdx = hasUncoloredNeighbours(idx)) != -1){
        if(setColors(unColoredIdx))
          return true;
      }

    }

    //Bước 2 : Quay lui
    vertexArray[idx]->color = -1;
    vertexArray[idx]->colored = false;
    return false;
}


int main()
{
  //Định nghĩa đỉnh
  Vertex vertexA, vertexB, vertexC, vertexD;
  vertexA.name = 'A';
  vertexB.name = 'B';
  vertexC.name = 'C';
  vertexD.name = 'D';

  //Thêm các đỉnh vào mảng
  vertexArray[0] = &vertexA;
  vertexArray[1] = &vertexB;
  vertexArray[2] = &vertexC;
  vertexArray[3] = &vertexD;

  //Đặt giá trị mặc định (không tô màu) cho tất cả các đỉnh
  for(int i=0; i<numOfVertices;i++){
    vertexArray[i]->colored = false;
    vertexArray[i]->color = -1;
  }

  //Bắt đầu tô màu với đỉnh đầu tiên
  bool hasSolution = setColors(0);

  //Kiểm tra xem tất cả các đỉnh đã được tô màu thành công hay chưa
  if (!hasSolution)
      printf("Không có giải pháp");
  else {
      for(int i=0; i<numOfVertices;i++){
          printf("%c %s \n",vertexArray[i]->name,colors[vertexArray[i]->color]);
      }
  }

  return 0;
}
