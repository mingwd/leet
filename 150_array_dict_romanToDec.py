class Solution:
    def romanToInt(self, s: str) -> int:

        symbol = {
                    'I': 1,
                    'IV': 4,
                    'V': 5,
                    'IX': 9,
                    'X': 10,
                    'XL': 40,
                    'L': 50,
                    'XC': 90,
                    'C': 100,
                    'CD': 400,
                    'D': 500,
                    'CM': 900,
                    'M': 1000
                }

        if len(s) == 1:
            return symbol[s[0]]

        index = 0
        total = 0
        while index < len(s) - 1:
            if s[index] == 'I' and s[index + 1] == 'V':
                total += 4
                index += 2
            elif s[index] == 'I' and s[index + 1] == 'X':
                total += 9
                index += 2
            elif s[index] == 'X' and s[index + 1] == 'L':
                total += 40
                index += 2
            elif s[index] == 'X' and s[index + 1] == 'C':
                total += 90
                index += 2
            elif s[index] == 'C' and s[index + 1] == 'D':
                total += 400
                index += 2
            elif s[index] == 'C' and s[index + 1] == 'M':
                total += 900
                index += 2
            else:
                total += symbol[s[index]]
                index += 1
        
        while index < len(s):
            total += symbol[s[index]]
            index += 1

        return total
    
    # 上面的有点长 这个更简单

    class Solution:
        def romanToInt(self, s: str) -> int:
            symbol = {
                'I': 1,
                'IV': 4,
                'V': 5,
                'IX': 9,
                'X': 10,
                'XL': 40,
                'L': 50,
                'XC': 90,
                'C': 100,
                'CD': 400,
                'D': 500,
                'CM': 900,
                'M': 1000
            }

            index = 0
            total = 0

            while index < len(s):
                # Try to match two characters first
                if index + 1 < len(s) and s[index:index+2] in symbol:
                    total += symbol[s[index:index+2]]
                    index += 2
                else:
                    total += symbol[s[index]]
                    index += 1

            return total

                    


            
        