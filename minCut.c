#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 200
#define MAX_LINE 3000

typedef struct vertex node;
typedef struct Edge edge;

struct Edge {
    int label;
    node *head;
    node *tail;
};
struct vertex {
    int label;
    edge *edges[MAX_LINE];
    int edge_num;
    int ns;
    int node_labels[MAX];
};

node *all_nodes[MAX];
edge *all_edges[MAX_LINE];
int node_label = 1;
int edge_label = 1;

void get_numbers(int *line_numbers, char *line) {
    int i, number, ch, j;
    i = j = number = 0;
    while(line[i]) {
        ch = line[i];
        if((ch == ' ' || ch == '\t') && number != 0) {
            line_numbers[j++] = number;
            number = 0;
        }
        else 
            number = number*10 + (int)(ch-48);
        i++;
    }
    line_numbers[j] = 0;
}

void create_node(int *line_numbers) {
    int i = 0;
    int number, j;
    node *new_node = malloc(sizeof(node));
    while ((number = line_numbers[i]) != 0) {
        if (i == 0) {
            new_node->label = number;
            new_node->edge_num = 0;
            new_node->ns = 1;
            new_node->node_labels[0] = number; 
            all_nodes[number-1] = new_node;
        }
        else {
            if (number < new_node->label) {
                int n = 0;
                node *this_node = all_nodes[number-1];
                while (n < this_node->edge_num) {
                    if (this_node->edges[n]->tail != NULL)
                        n++;
                    else {
                        j = new_node->edge_num++;
                        new_node->edges[j] = this_node->edges[n];
                        this_node->edges[n]->tail = new_node;
                        break;
                    }
                }
            }
            else {
                edge *new_edge = malloc(sizeof(edge));
                new_edge->label = edge_label;
                new_edge->head = new_node;
                new_edge->tail = NULL;
                j = new_node->edge_num++;
                new_node->edges[j] = new_edge;
                all_edges[edge_label-1] = new_edge;
                edge_label++;
            }
        }
        i++;
    }
    if (line_numbers[0] == 200) 
        all_edges[edge_label-1] = NULL;
}


int min_cut(node *all_nodes[],edge *all_edges[]) {
    int n, edge_num,node_remained, min_cut;
    edge_num = min_cut = 0;
    node_remained = 200;
    while(all_edges[edge_num] != NULL)
        edge_num++;
    srand(time(NULL));
    while(node_remained > 2){
        node *nodeA, *nodeB;
        edge *edgeC;
        bool found = false;
        while(!found) {
            n = rand()/(float)RAND_MAX *(edge_num-1);
            edgeC = all_edges[n];
            while(edgeC->label == 0 && n < edge_num) {
                n = n+1; 
                edgeC = all_edges[n];
            }
            if(edgeC->label !=0 ) {
     //           printf("chosed: %d\t",edgeC->label);
                edgeC->label = 0;
                node_remained--;
       //         printf("node_ramained: %d\t",node_remained);
                found = true;
            }
        }
        nodeA = edgeC->head;
        nodeB = edgeC->tail;
      //  printf("%d\t",nodeB->label);
        int nodeA_num, nodeB_num;
        nodeA_num = nodeA->ns;
        nodeB_num = nodeB->ns;
//        printf("%d\t%d\t",nodeA_num,nodeB_num);
        int total_num = nodeA_num + nodeB_num;
        for (int l=nodeB_num; l<total_num; l++) {
            nodeB->node_labels[l] = nodeA->node_labels[nodeA_num-1];
            nodeA_num--;
            nodeB->ns++;
        }
  //      printf("after: %d\n",nodeB->ns);
        nodeA->label = 0;
        int i = 0;
         while(i < nodeA->edge_num) {
            edge *edgeA = nodeA->edges[i];
            i++;
            if (edgeA->label == 0) 
                continue;
            else if (edgeA->head == nodeA)
                edgeA->head = nodeB;
            else
                edgeA->tail = nodeB;
            nodeB->edges[nodeB->edge_num] = edgeA;
            nodeB->edge_num++;
        }
        int j = 0;
  //      edgeB_num = nodeB->edge_num;
         while(j < nodeB->edge_num) {
            edge *edgeB = nodeB->edges[j];
            if (edgeB->head == edgeB->tail) {
            //    nodeB->edge_num--;
                edgeB->label = 0;
             //   swap(nodeB->edges,j, nodeB->edge_num);
            }
            j++;
        }
    }
    printf("node left: %d\n",node_remained);

    node *node_left;
    for(int k=0; k<200; k++) {
   //     printf("%d\t%d\n",all_nodes[k]->label,all_nodes[k]->ns);
        if(all_nodes[k]->label != 0) {
            node_left = all_nodes[k];
            printf("%d\t%d\t",node_left->edge_num,node_left->ns);
            printf("%d\n",node_left->label);
        }
    }
    int edgeN = 0;

//    while(edgeN < node_left->edge_num) {
  //      edge *edge_left = node_left->edges[edgeN];
  //      if (edge_left->label !=0)
 //           min_cut++;
 //       edgeN++;
 //   }
//        edge edgeL = *nodeL->edges[k];
 //       if(edgeL.label != 0)
 //           min_cut++;
 //   }
    printf("min cut: %d\n",min_cut);
    return min_cut;

}



int main(void) {
    FILE *fp;
    int temp;
    char line[MAX];
    int line_numbers[MAX];
    fp = fopen("kargerMinCut.txt","r");
        while(fgets(line, MAX, fp) != NULL) {
            get_numbers(line_numbers, line);
            create_node(line_numbers);
         }
        temp = min_cut(all_nodes,all_edges);
    return 0; 
}


