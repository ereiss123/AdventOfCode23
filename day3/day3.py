"""
Day 3: Engine Parts
"""
debug = False

def is_num(s):
    try:
        int(s)
        return True
    except ValueError:
        return False
    
def find_num(i,j, mat):
    # Check left
    num = ''
    while is_num(mat[i][j]) and j >= 0:
        print(mat[i][j]) if debug else None
        j -= 1
    # gather digits
    j += 1
    while j < len(mat[i]) and is_num(mat[i][j]):
        num += mat[i][j]
        mat[i][j] = '.' # mark as visited
        j += 1
    print(num) if debug else None
    return int(num),mat

def part1():
    pass
    total = 0
    if debug:
        file = "test.txt"
    else:
        file = "input.txt"
    # Save input
    with open(file, "r") as f:
        mat = []
        for line in f:
            mat.append(line.strip())
    mat = [list(line) for line in mat]
    print(mat) if debug else None
    # Process input
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if not ('0' <= mat[i][j] <= '9' or mat[i][j] == '.'):
                print(f"Found item: {mat[i][j]}") if debug else None
                # check up
                if i > 0 and is_num(mat[i-1][j]):
                    num, mat = find_num(i-1,j,mat)
                    total += num
                # check down
                if i < len(mat)-1 and is_num(mat[i+1][j]):
                    num, mat = find_num(i+1,j,mat)
                    total += num
                # check left
                if j > 0 and is_num(mat[i][j-1]):
                    num, mat = find_num(i,j-1,mat)
                    total += num
                # check right
                if j < len(mat[i])-1 and is_num(mat[i][j+1]):
                    num, mat = find_num(i,j+1,mat)
                    total += num
                # check up-left
                if i > 0 and j > 0 and is_num(mat[i-1][j-1]):
                    num, mat = find_num(i-1,j-1,mat)
                    total += num
                # check up-right
                if i > 0 and j < len(mat[i])-1 and is_num(mat[i-1][j+1]):
                    num, mat = find_num(i-1,j+1,mat)
                    total += num
                # check down-left
                if i < len(mat)-1 and j > 0 and is_num(mat[i+1][j-1]):
                    num, mat = find_num(i+1,j-1,mat)
                    total += num
                # check down-right
                if i < len(mat)-1 and j < len(mat[i])-1 and is_num(mat[i+1][j+1]):
                    num, mat = find_num(i+1,j+1,mat)
                    total += num
    print(total)            
                    
def part2():
    total = 0
    if debug:
        file = "test.txt"
    else:
        file = "input.txt"
    # Save input
    with open(file, "r") as f:
        mat = []
        for line in f:
            mat.append(line.strip())
    mat = [list(line) for line in mat]
    print(mat) if debug else None
    # Process input
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if mat[i][j] == '*':
                num_count = 0
                nums = []
                print(f"Found item: {mat[i][j]}") if debug else None
                # check up
                if i > 0 and is_num(mat[i-1][j]):
                    num,mat = find_num(i-1,j,mat)
                    num_count += 1
                    nums.append(num)
                    
                # check down
                if i < len(mat)-1 and is_num(mat[i+1][j]):
                    num,mat = find_num(i+1,j,mat)
                    num_count += 1
                    nums.append(num)
                # check left
                if j > 0 and is_num(mat[i][j-1]):
                    num,mat = find_num(i,j-1,mat)
                    num_count += 1
                    nums.append(num)
                # check right
                if j < len(mat[i])-1 and is_num(mat[i][j+1]):
                    num,mat = find_num(i,j+1,mat)
                    num_count += 1
                    nums.append(num)
                # check up-left
                if i > 0 and j > 0 and is_num(mat[i-1][j-1]):
                    num,mat = find_num(i-1,j-1,mat)
                    num_count += 1
                    nums.append(num)
                # check up-right
                if i > 0 and j < len(mat[i])-1 and is_num(mat[i-1][j+1]):
                    num,mat = find_num(i-1,j+1,mat)
                    num_count += 1
                    nums.append(num)
                # check down-left
                if i < len(mat)-1 and j > 0 and is_num(mat[i+1][j-1]):
                    num,mat = find_num(i+1,j-1,mat)
                    num_count += 1
                    nums.append(num)
                # check down-right
                if i < len(mat)-1 and j < len(mat[i])-1 and is_num(mat[i+1][j+1]):
                    num,mat = find_num(i+1,j+1,mat)
                    num_count += 1
                    nums.append(num)
                print(f"num_count: {num_count}") if debug else None
                if num_count == 2:
                    num1 = nums[0]
                    num2 = nums[1]
                    total += num1*num2
    print(total)
               
                
    
if __name__ == "__main__":
    part1()
    part2()