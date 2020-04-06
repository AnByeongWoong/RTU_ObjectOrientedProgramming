#include <iostream> // to include cout and cin objects
#include <cassert> // to be able to use function assert()
#include "TodoList.h" // to be able to use Todo class
:::
using namespace std; // to shortcut the standard namespace
int main()
{
    TodoList todos;
    DateTime test_date_time{ DateTime::today() };

    test_date_time += 1; // tomorrow

    todos.add_task("Buy a milk", Task::PRIORITY::NORMAL, test_date_time);
    assert(1 == todos.get_tasks_count());
    
    test_date_time -= 2; // yesterday
    todos.add_task("Buy a bread", Task::PRIORITY::HIGH, test_date_time);
    assert(2 == todos.get_tasks_count());
    
    // Shows all tasks
    cout << "All tasks\n====================\n";
    todos.send_to(cout);
    
    // Shows due tasks only
    cout << "Due tasks\n====================\n";

    auto is_due = [&](const Task& t) { return t.is_due(); };
    
    todos.send_to(std::cout, is_due);
    
    cout << "Completing 1st task ...\n";
    todos.complete_task(0);
    assert(!todos.task_is_due(0));
    
    cout << "Due tasks\n====================\n";
    todos.send_to(std::cout, is_due);
    
    /// Removes done tasks (must be implemented)
    todos.remove_done_tasks();
    
    #ifndef NDEBUG
    cout << "Press Enter to exit";
    cin.get(); /// wait for the Enter key
    #endif
    return 0;
}