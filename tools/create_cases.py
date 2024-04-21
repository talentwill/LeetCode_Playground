import random
import logging

index = 1


def generate_random_integer_list(size=10, low=1, high=10):
    result = []
    for _ in range(size):
        result.append(random.randint(low, high))
    logging.debug(result)
    return result


def convert_list_to_cpp_vector(values: list, fout=None):
    name = f"vector<int> v{index}" + " { "
    result = name + ", ".join(map(str, values)) + " };"
    print(result)
    logging.debug(result)
    return result


def create_integer_arrays(fout=None):
    count = 2
    for _ in range(count):
        values = generate_random_integer_list(10, 1, 10)
        line = convert_list_to_cpp_vector(values)
        if fout:
            fout.write(line + "\n")


# if __name__ == "__main__":
#     logging.basicConfig(level=logging.DEBUG)
#     with open("tools/created_cases.txt", "a", encoding="utf-8") as fout:
#         create_integer_arrays(fout)


convert_list_to_cpp_vector([1,2,1,3,5,6,4])