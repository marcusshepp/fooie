import math
import copy

def solution(x):
        x = [i for i in str(x)]
            nums = []
                for index, value in enumerate(x):
                            # replace i and i + 1 with the average rounded
                                    # append to nums
                                            if index < len(x) - 1:
                                                            first_number = x[index]
                                                                        second_number = x[index + 1]
                                                                                    average = rounded_up_average(first_number, second_number)
                                                                                                new_list = copy.copy(x)
                                                                                                            new_list[index] = None
                                                                                                                        new_list[index + 1] = str(average)
                                                                                                                                    new_num = int("".join([i for i in new_list if i != None]))
                                                                                                                                                nums.append(new_num)
                                                                                                                                                    return max(nums)

                                                                                                                                                def rounded_up_average(x, y):
                                                                                                                                                        x, y = int(x), int(y)
                                                                                                                                                            average = math.ceil((float(x) + float(y)) / float(2))
                                                                                                                                                                if average - int(average) == 0.5:
                                                                                                                                                                            return int(average) + 1
                                                                                                                                                                            return int(average)
