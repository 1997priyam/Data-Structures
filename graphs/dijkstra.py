import sys

def dijkstra(G, start_node):
    visited = [False for _ in range(len(G))]
    distance = [float('inf') for _ in range(len(G))]
    distance[start_node] = 0.0
    for _ in range(len(G)):
        current = get_min_index(visited, distance)
        if current == None:
            break
        visited[current] = True

        for index, weight in enumerate(G[current]):
            if (weight > 0 and not visited[index] and (distance[index] > distance[current] + weight)):
                distance[index] = distance[current] + weight
    return distance

def get_min_index(visited, distance):
    min_index = None
    min_value = float('inf')
    for index, dist in enumerate(distance):
        if dist < min_value and not visited[index]:
            min_value = dist
            min_index = index
    return min_index

def help_menu():
    print("\nPossible Commands are:")
    print("dijkstra x - Runs Dijkstra starting at node X. X must be an integer")
    print("help - prints this menu")
    print("exit or ctrl-d - Exits the program\n")

def read_file(filename):
    input_file_content = None
    try:
        with open(filename) as input_file:
            input_file_content = input_file.read()
    except FileNotFoundError:
        print("This file is not present. Please enter the correct filename")
    except Exception as e:
        print("Unknown error occured, exiting.")
        print(e)
        sys.exit(1)
    finally:
        return input_file_content

def parse_file(input_file_content):
    edges = []
    all_lines = input_file_content.split("\n")
    number_of_nodes = int(all_lines[0])
    all_lines.pop(0)
    for each_line in all_lines:
        from_node, to_node, weight = each_line.split(" ")
        edges.append([int(from_node), int(to_node), float(weight)])
    return (number_of_nodes, edges)

def create_adjacency_matrix(number_of_nodes, edges):
    G = [ [-1 for _ in range(number_of_nodes)] for _ in range(number_of_nodes) ]
    for edge in edges:
        G[edge[0]][edge[1]] = edge[2]
    return G

def main():
    while True:
        print("File containing graph: ", end =" ")
        file_name = input()
        input_file_content = read_file(file_name)
        if input_file_content is not None:
            break
    try:
        number_of_nodes, edges = parse_file(input_file_content)
        G = create_adjacency_matrix(number_of_nodes, edges)
    except Exception as e:
        print("Unable to parse and create the adjacency matrix, please check the content of input file.")
        return
    help_menu()
    while True:
        try:
            print("Enter command: ", end =" ")
            command = input()
            if command.startswith("dijkstra"):
                print(dijkstra(G, int(command.split(" ")[1])))
            elif command == "help":
                continue
            elif command == "exit":
                return
            else:
                print("Invalid Comamnd, Please try again!")
        except EOFError:
            return

if __name__ == "__main__":
    main()
    print("Bye")