'''
Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.

You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).
'''

def solution(a):
    N = len(a)
    cl = 0
    cu = N - 1
    while cl < cu:
        m = cu - cl + 1
        for d in range(m - 1):
            ix1 = [cl, cl + d]
            ix2 = [cl + d, cu]
            ix3 = [cu, cu - d]
            ix4 = [cu - d, cl]
            # print(ix1, ix2, ix3, ix4)
            a[ix1[0]][ix1[1]], a[ix2[0]][ix2[1]] = a[ix2[0]][ix2[1]], a[ix1[0]][ix1[1]]
            a[ix1[0]][ix1[1]], a[ix3[0]][ix3[1]] = a[ix3[0]][ix3[1]], a[ix1[0]][ix1[1]]
            a[ix1[0]][ix1[1]], a[ix4[0]][ix4[1]] = a[ix4[0]][ix4[1]], a[ix1[0]][ix1[1]]
        cl += 1
        cu -= 1
    return a
  
if __name__=="__main__":
    mat = [[10,9,6,3,7], 
            [6,10,2,9,7], 
            [7,6,3,8,2], 
            [8,9,7,9,9], 
            [6,8,6,8,2]]
    print('matrix:')
    for row in mat:
        print(row)
    mat_rotated=solution(mat)
    print("rotated matrix:")
    for row in mat_rotated:
        print(row)  
