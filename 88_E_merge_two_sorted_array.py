class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """



        n1_index = m - 1
        move_to = len(nums1) - 1
        
        
        while n1_index >= 0:
            nums1[move_to] = nums1[n1_index]
            n1_index -= 1
            move_to -= 1

        # 上面的很关键

        n1_index = len(nums1) - m
        n2_index = 0
        result_index = 0

        while n2_index < n and n1_index < len(nums1):
            if nums1[n1_index] < nums2[n2_index]:
                nums1[result_index] = nums1[n1_index]
                n1_index += 1
                result_index += 1
            else:
                nums1[result_index] = nums2[n2_index]
                n2_index += 1
                result_index += 1

        while n1_index < len(nums1):
            nums1[result_index] = nums1[n1_index]
            result_index += 1
            n1_index +=1

        while n2_index < len(nums2):
            nums1[result_index] = nums2[n2_index]
            result_index += 1
            n2_index += 1

            
    class Solution:
        def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
            """
            Do not return anything, modify nums1 in-place instead.
            """
            # could either list empty?
            # shall I return or do it in place?
            # m and n are always vaid?
            
            i = m - 1
            j = n - 1
            curr = m + n - 1

            while curr >= 0:
                if i >= 0 and j >= 0:
                    if nums1[i] > nums2[j]:
                        nums1[curr] = nums1[i]
                        i -= 1
                    else:
                        nums1[curr] = nums2[j]
                        j -= 1
                elif j >= 0:
                    nums1[curr] = nums2[j]
                    j -= 1
                curr -= 1