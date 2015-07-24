-- Simple fibonacci list generator in haskell

fib last2 last1 = cur : (fib last1 cur)
                where cur = last2+last1

allFibs = 0 :1 : (fib 0 1)
