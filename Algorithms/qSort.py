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
            a[i], a[j] = a[j], a[i]
            i += 1
            j -= 1

    qSort(a, l, j);
    qSort(a, i, r);

    return a

if __name__ == "__main__":
    ar = [-15,5,3,-17,-10,84,21,19,-6,0,-22,9,18,2,43,90,56,-1,21,36]
    print(f"sample array: {ar}")
    ar = qSort(ar, 0, len(ar)-1)
    print(f"sorted array: {ar}")
