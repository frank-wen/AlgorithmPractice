class Node:
    def __init__(self,label,out_edges,in_edges,explored,explored2,instack):
        self.label = label
        self.out_edges = out_edges
        self.in_edges = in_edges
        self.explored = explored
        self.explored2 = explored2
        self.instack = instack

class Edge:
    def __init__(self,tail,head):
        self.head = head
        self.tail = tail

all_nodes = list()
all_nodes2 = list()
all_edges = list()

for i in range(875714):
    all_nodes.append(Node(i+1,list(),list(),False,False,False))

fin2 = open('SCC.txt')
for line in fin2:
    strings = line.split()
    tail_label = int(strings[0])
    head_label = int(strings[1])
    head = all_nodes[head_label-1]
    tail = all_nodes[tail_label-1]
    edge = Edge(tail,head)
    all_edges.append(edge)
    tail.out_edges.append(edge)
    head.in_edges.append(edge)

print(len(all_edges))

temp_list = list()
def DFS1(node):
    stack = list()
    stack.append(node)
    node.instack = True
    while len(stack) > 0:
        temp = stack.pop()
        temp.instack = False
        if temp.explored == False:
            temp.explored = True
            temp_list.append(temp)
            for edge in temp.in_edges:
                if edge.tail.explored == False and edge.tail.instack == False:
                    stack.append(edge.tail)
                    edge.tail.instack = True

def DFS2(node,s):
    stack = list()
    stack.append(node)
 #   node.instack = True
    leader_num = len(leaders)
    while len(stack) > 0:
        the_node = stack.pop()
 #       the_node.instack = False
        temp = leaders[leader_num-1]
        if the_node.explored2 == False:
            the_node.explored2 = True
            leaders[leader_num-1] = (temp[0],temp[1]+1)
            for edge in the_node.out_edges:
                if edge.head.explored2 == False: # and edge.head.instack == False:
                    stack.append(edge.head)
#                    edge.head.instack = True

for node in all_nodes:
    if node.explored == False:
        DFS1(node)
    while(len(temp_list) > 0):
        all_nodes2.append(temp_list.pop())

leaders = list()

while len(all_nodes2) > 0:
    node = all_nodes2.pop()
    if node.explored2 == False:
        s = node.label
        if len(leaders) < 50:
            print(s,end='\t')
        leaders.append((s,0))
        DFS2(node,s)

print('number of scc:',len(leaders))
leaders.sort(key = lambda num:num[1],reverse = True)
count = 0
for leader in leaders:
    if count < 100:
        print(leader[1],end='\t')
        count = count+1

