memo = [0] * 1000

def fib(n):
    if n < 2:
        return 1
    return fib(n-1) + fib(n-2)


def fib_memo(n):
    if memo[n] != 0:
        return memo[n]

    if n < 2:
        resultado = 1
    else:
        resultado = fib_memo(n-1) + fib_memo(n-2)

    memo[n] = resultado
    return resultado
