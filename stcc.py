import sys
sys.setrecursionlimit(10000)
import random
class Node:
    def __init__(self,label,out_edges,in_edges,explored,explored2,leader):
        self.label = label
        self.out_edges = out_edges
        self.in_edges = in_edges
        self.explored = explored
        self.explored2 = explored2
        self.leader = leader

class Edge:
    def __init__(self,tail,head):
        self.head = head
        self.tail = tail

all_nodes = list()
all_nodes2 = list()
big = 875714
test = 8
for i in range(test):
    all_nodes.append(Node(i+1,list(),list(),False,False,0))

fin = open('test_data')
for line in fin:
    strings = line.split()
    tail_label = int(strings[0])
    head_label = int(strings[1])
    head = all_nodes[head_label-1]
    tail = all_nodes[tail_label-1]
    edge = Edge(tail,head)
    tail.out_edges.append(edge)
    head.in_edges.append(edge)


def DFS1(node):
    node.explored = True
    for edge in node.in_edges:
        if edge.tail.explored == False:
            DFS1(edge.tail)
    all_nodes2.append(node)

def DFS2(node,s):
    node.explored2 = True
    node.leader = s
    for edge in node.out_edges:
        temp = leaders[len(leaders)-1]
        if edge.head.explored2 == False:
            leaders[len(leaders)-1] = (temp[0],temp[1]+1)
            DFS2(edge.head,s)

for node in all_nodes:
    if node.explored == False:
        DFS1(node)

for node in all_nodes2:
    print(node.label)

leaders = list()
while(len(all_nodes2) > 0):
    node = all_nodes2.pop()
    if node.explored2 == False:
        s = node.label
        leaders.append((s,1))
        DFS2(node,s)
#for leader in leaders:
#    print(leader)
