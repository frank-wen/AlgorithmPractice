t = 0
def change_out_var():
    global t
    for i in range(10):
        t = t+1

change_out_var()
print(t)
