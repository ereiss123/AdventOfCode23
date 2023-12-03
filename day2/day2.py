"""
C was painful, I think I will do this one in Python
"""

def part1(red: int, green: int, blue: int) -> bool:
    with open("input.txt", "r") as f:
        for line in f:
            # print(line)
            line = line.strip().split(" ")
            prev_word = ""
            for word in line:
                if prev_word == "Game":
                    game = ord(word[0]) - ord('0')
                if word[:3] == "red":
                    print("red "+prev_word)
                elif word[:5] == "green":
                    print("green "+prev_word)
                elif word[:4] == "blue":
                    print("blue "+prev_word)
                prev_word = word
            
    
    
if __name__ == "__main__":
    part1(12,13,14)
    #part2()