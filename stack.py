import time

def display_stack(stack):
    """Displays a stack with a fancy animated effect."""
    if not stack:
        print("\n🟦 Stack is empty! 🟦\n")
        return
    
    print("\n🟦 Stack Display 🟦\n")
    for i in range(len(stack)-1, -1, -1):
        print(f"  | {stack[i]} |  ")
        time.sleep(0.2)  # Adding a slight delay for animation effect
    print("  -----  ")

# Example Usage
stack = [10, 20, 30, 40, 50]
display_stack(stack)
