"""
C was painful, I think I will do this one in Python
"""

def part1(red: int, green: int, blue: int) -> int:
    with open("input.txt", "r") as f:
        round = 0
        total = 0
        for line in f:
            round += 1
            total += round
            line = line.strip().split(" ")
            
            
            borders = []
            for idx in range(len(line)):
                if line[idx][-1] == ':':
                    borders.append(idx+1)
                if line[idx][-1] == ';':
                    borders.append(idx+1)
            borders.append(len(line))
            
            
            bad_round = False
            for idx in range(len(borders)-1):
                frag = line[borders[idx]:borders[idx+1]]
                # print(frag)
                prev_word = ""
                if bad_round:
                    break
                for word in frag:
                    if word[:3] == "red":
                        if int(prev_word) > red:
                            total -= round
                            bad_round = True
                            break
                    elif word[:5] == "green":
                        if int(prev_word) > green:
                            total -= round
                            bad_round = True
                            break
                    elif word[:4] == "blue":
                        x = int(prev_word)
                        if int(prev_word) > blue:
                            total -= round
                            bad_round = True
                            break
                    prev_word = word  
                    
                        
        return total
    return -1
            
    
    
if __name__ == "__main__":
    print(part1(12,13,14))
    #part2()