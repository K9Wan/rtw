def p(a,b,c=None):
    '''implement equivalent of built_in pow(), maybe'''
    def pp(a,b):
        if b == 0:
            return 1
        if b == 1:
            return a
        if b%2 == 0:
            return pp(a*a,b//2)
        return a*pp(a*a,b//2)
    if c is None:
        if isinstance(b, int):
            return pp(a,b)
        return a**b
    if c == 0:
        raise ValueError('e')
    if not all(map(lambda x: isinstance(x, int),(a,b,c))):
        raise TypeError('e')
    if b == 0:
        return 1
    rs = []
    r = a % c
    for i in range(c):
        if r not in rs:
            rs.append(r)
        else:
            break
        r = r * a % c
    if 1 not in rs:
        if b < 0:
            raise ValueError('e')
    #print(rs)
    idx = rs.index(rs[-1] * a % c)
    #print(idx)
    rs_repeat = rs[idx:]
    #print(rs_repeat)
    repeat_len = len(rs_repeat)
    if b < 0:
        return rs[(b-1)%repeat_len]
    if 0 < b <= idx:
        return rs[b-1]
    return rs[idx+(b-1-idx)%repeat_len]
