class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: # 很关键
            return s

        rows = [""] * numRows
        index = 0
        going_down = False # 很关键，因为第一个好好看看
        for char in s:
            rows[index] += char

            if index == 0 or index == numRows - 1:
                going_down = not going_down
            
            index += 1 if going_down else -1      #也很关键
            # index += （1 if going_down else - 1）

        return "".join(rows)
            





            


        