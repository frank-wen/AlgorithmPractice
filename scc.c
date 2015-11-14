#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5200000

typedef struct Node node;
typedef struct Edge edge;
struct Node {
    int label;
    int ia;
    int ib;
    struct Edge *out_edges[15];
  //  struct Edge *in_edges[50];
    bool explored;
    bool explored2;
};

struct Edge {
    node *head;
    node *tail;
};



int main(void) {
    node *all_nodes = malloc(sizeof(node)*875714);
    edge *all_edges = malloc(sizeof(edge)*MAX);
    int i = 0;
    while  (i < 875714) {
        node *temp = all_nodes+i;
        temp->label = i+1;
        temp->explored = false;
        temp->explored2 = false;
        temp->ia = 0;
        temp->ib = 0;
        i++;
    }

    FILE *fp;
    if ((fp=fopen("SCC.txt","r+")) == NULL)
        puts("file open error");
    int a, b,edge_label;
    edge_label = 0;
    node *head;
    node *tail;
    while (fscanf(fp,"%d %d", &a,&b) == 2) {
        int ia,ib;
        head = all_nodes + (b-1);
        tail = all_nodes + (a-1);
        edge *new_edge = all_edges + edge_label;
        new_edge->head = head;
        new_edge->tail = tail;
        ib = all_nodes[b-1].ib++;
       // all_nodes[b-1].in_edges[ib] = all_edges + edge_label;
        ia = all_nodes[a-1].ia++;
        all_nodes[a-1].out_edges[ia] = all_edges + edge_label;
        edge_label++;
    }
    int index = 5713;
    while(index > 5710) {
        node temp = all_nodes[index];
        printf("%d\t",temp.label);
        for (int j=0; j<temp.ia; j++){
            node to_node = *temp.out_edges[j]->head;
            printf("%d\t",to_node.label);
        }
        putchar('\n');
        index--;
    }
    return 0;
}
        

/*
def DFS1(node):
    stack = list()
    first = True
    stack.append(node)
    while len(stack) > 0:
        temp = stack.pop()
        if temp.explored == False:
            temp.explored = True
            if first == False:
                all_nodes2.append(temp)
            for edge in temp.in_edges:
                if edge.tail.explored == False:
                    stack.append(edge.tail)
                    first = False

def DFS2(node,s):
    stack = list()
    stack.append(node)
    leader_num = len(leaders)
    while len(stack) > 0:
        the_node = stack.pop()
        temp = leaders[leader_num-1]
        if the_node.explored2 == False:
            the_node.explored2 = True
            leaders[leader_num-1] = (temp[0],temp[1]+1)
            node.leader = s
            for edge in the_node.out_edges:
                if edge.head.explored2 == False:
                    stack.append(edge.head)

for node in all_nodes:
    if node.explored == False:
        DFS1(node)
        all_nodes2.append(node)

leaders = list()
while(len(all_nodes2) > 0):
    node = all_nodes2.pop()
    if node.explored2 == False:
        s = node.label
        leaders.append((s,0))
        DFS2(node,s)

print('number of scc:',len(leaders))
leaders.sort(key = lambda num:num[1],reverse = True)
count = 0
for leader in leaders:
    if count < 5:
        print(leader)
        count = count+1
*/
