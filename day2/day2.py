"""
C was painful, I think I will do this one in Python
"""
import sys

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
    
def part2() -> int:
    with open("input.txt", "r") as f:
        total = 0
        for line in f:
            line = line.strip().split(" ")
            
            
            borders = []
            for idx in range(len(line)):
                if line[idx][-1] == ':':
                    borders.append(idx+1)
                if line[idx][-1] == ';':
                    borders.append(idx+1)
            borders.append(len(line))
            
            red_max = 0
            green_max = 0 
            blue_max = 0
            for idx in range(len(borders)-1):
                frag = line[borders[idx]:borders[idx+1]]
                prev_word = ""
                for word in frag:
                    if word[:3] == "red":
                        if int(prev_word) > red_max:
                            red_max = int(prev_word)
                    elif word[:5] == "green":
                        if int(prev_word) > green_max:
                            green_max = int(prev_word)
                    elif word[:4] == "blue":
                        if int(prev_word) > blue_max:
                            blue_max = int(prev_word)
                    prev_word = word 
            # print(f"{''.join(line)}  {red_max} {green_max} {blue_max} {red_max*green_max*blue_max} {total}")
            total += red_max*green_max*blue_max             
        return total      
    
    
if __name__ == "__main__":
    print(part1(12,13,14))
    print(part2())