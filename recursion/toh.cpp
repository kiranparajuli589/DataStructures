#include <iostream>
#include <stack>

using namespace std;

void displayStack(stack<int>& s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void displayTower(
    stack<int> source,
    stack<int> auxiliary,
    stack<int> target,
    char sourcePeg = 'A',
    char targetPeg = 'C',
    char auxiliaryPeg = 'B'
) {
    cout << sourcePeg << ": ";
    displayStack(source);
    cout << auxiliaryPeg << ": ";
    displayStack(auxiliary);
    cout << targetPeg << ": ";
    displayStack(target);
    cout << endl;
}

void tohMove(
    int diskNum,
    stack<int>& source,
    stack<int>& target,
    stack<int>& auxiliary,
    char sourcePeg = 'A',
    char targetPeg = 'C',
    char auxiliaryPeg = 'B'
) {
    if (diskNum == 1) {
        // Base case: If there is only 1 disk, move it from source to target peg
        cout << "Move disk 1 from " << sourcePeg << " to " << targetPeg << endl;

        target.push(source.top());
        source.pop();

        displayTower(source, auxiliary, target, sourcePeg, targetPeg, auxiliaryPeg);
    } else {
        // Move (n-1) disks from source to auxiliary peg
        tohMove(diskNum - 1, source, auxiliary, target, sourcePeg, auxiliaryPeg, targetPeg);

        // Move the nth disk from source to target peg
        cout << "Move disk " << diskNum << " from " << sourcePeg << " to " << targetPeg << endl;
        target.push(source.top());
        source.pop();

        displayTower(source, auxiliary, target, sourcePeg, targetPeg, auxiliaryPeg);

        // Move (n-1) disks from auxiliary to target peg
        tohMove(diskNum - 1, auxiliary, target, source, auxiliaryPeg, targetPeg, sourcePeg);
    }
}

int main() {
    int numDisks;

    cout << "Enter number of disks: ";
    cin >> numDisks;

    stack<int> sourceStack;
    stack<int> targetStack;
    stack<int> auxiliaryStack;

    cout << "Tower of Hanoi with " << numDisks << " disks:" << endl;

    for (int i = numDisks; i > 0; i--) {
        sourceStack.push(i);
    }

    cout << "Initial state:" << endl;
    displayTower(sourceStack, auxiliaryStack, targetStack);

    cout << "Moving disks from A to C:" << endl;

    tohMove(
        numDisks,
        sourceStack,
        targetStack,
        auxiliaryStack
    );

    cout << endl;
    return 0;
}
