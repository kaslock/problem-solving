target = input()
bomb = input()

stack = []
p = len(bomb)*(-1)

for t in target:
    stack.append(t)
    if t == bomb[-1]:
        for i, s in enumerate(stack[p:]):
            if bomb[i] != s:
                break
            if i + 1 == len(bomb):
                del stack[p:]

if stack == []:
    print("FRULA")
else:
    print("".join(stack))