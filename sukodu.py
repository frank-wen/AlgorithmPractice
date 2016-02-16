import random
sukodu = list()

class Node:
    def __init__(self,block,ans,row,col,candidate,pre,nex,solved):
        self.ans = ans
        self.block = block
        self.row = row
        self.col = col
        self.candidate = candidate
        self.pre = pre
        self.nex = nex
        self.solved = solved

for i in range(81):
    row = i//9
    col = i%9
    block = row//3*3 + col//3
    if i > 0:
        pre = sukodu[i-1]
    else:
        pre = None
    sukodu.append(Node(block,0,row,col,list(range(1,10)),pre,None,False))

for i in range(80):
    node = sukodu[i]
    node.nex = sukodu[i+1]

for i in range(1,7):
    while True:
        row = random.randrange(9)
        col = random.randrange(9)
        node = sukodu[row*9+col]
        if node.solved == False:
            node.ans = i
            node.solved = True
            print(node.row,node.col,node.ans)
            break


def get_candidate(sukodu,nodeA):
    row = nodeA.row
    col = nodeA.col
    block = nodeA.block
    for node in sukodu:
        if node.row == row or node.col == col or node.block == block:
            if node.ans in nodeA.candidate:
                nodeA.candidate.remove(node.ans)
    if len(nodeA.candidate) == 0:
        return False
    return True
        
def solve(sukodu,node):
    if get_candidate(sukodu,node) == False:
        if node.pre != None:
            node.candidate = list(range(1,10))
            node.ans = 0
            node.solved = False
            if node.pre.solved == False:
                solve(sukodu,node.pre)
            else:
                solve(sukodu,node.pre.pre)
    else:
        node.ans = node.candidate[0] #node.candidate.pop()
        node.solved = True
        if node.nex != None:
            if node.nex.solved == False:
                solve(sukodu,node.nex)
            else:
                solve(sukodu,node.nex.nex)

for node in sukodu:
    if node.solved == False:
        solve(sukodu,node)
n = 0
for node in sukodu:
    print(node.ans,end='\t')
    if n%9 == 8:
        print(' ')
    n = n+1
    #node.candidate = list(range(1,10))
   # get_candidate(sukodu,node)
   # print(node.candidate)
