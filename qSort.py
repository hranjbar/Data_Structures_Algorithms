"""
Implementation of quick sort with in-function partition - still recursive
"""
def qSort(a, l, r):

    if l >= r:
        return a

    x = a[l]
    i = l
    j = r

    while i <= j:
        while a[i] < x:
            i += 1
        while a[j] > x:
            j -= 1
        if i <= j:
            t = a[i]
            a[i] = a[j]
            a[j] = t
            i += 1
            j -= 1

    qSort(a, l, j);
    qSort(a, i, r);

    return a
