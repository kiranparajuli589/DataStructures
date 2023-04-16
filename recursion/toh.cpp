#include <iostream>
#include <stack>

using namespace std;

void moveDiskStep(int diskNum, char source, char target, char auxiliary) {
    if (diskNum == 1) {
        // Base case: If there is only 1 disk, move it from source to target peg
        cout << "Move disk 1 from " << source << " to " << target << endl;
    } else {
        // Move (n-1) disks from source to auxiliary peg
        moveDiskStep(diskNum - 1, source, auxiliary, target);
        // Move the nth disk from source to target peg
        cout << "Move disk " << diskNum << " from " << source << " to " << target << endl;
        // Move (n-1) disks from auxiliary to target peg
        moveDiskStep(diskNum - 1, auxiliary, target, source);
    }
}

void tohStep(int numDisks, char source = 'A', char target = 'C', char auxiliary = 'B') {
    cout << "Tower of Hanoi with " << numDisks << " disks:" << endl;
    moveDiskStep(numDisks, source, target, auxiliary);
}

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

void move(
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
        target.push(source.top());
        source.pop();

        displayTower(source, auxiliary, target, sourcePeg, targetPeg, auxiliaryPeg);
    } else {
        // Move (n-1) disks from source to auxiliary peg
        move(diskNum - 1, source, auxiliary, target, sourcePeg, auxiliaryPeg, targetPeg);
        // Move the nth disk from source to target peg
        target.push(source.top());
        source.pop();

        displayTower(source, auxiliary, target, sourcePeg, targetPeg, auxiliaryPeg);
        // Move (n-1) disks from auxiliary to target peg
        move(diskNum - 1, auxiliary, target, source, auxiliaryPeg, targetPeg, sourcePeg);
    }
}

int main() {
    int numDisks = 4; // Number of disks in Tower of Hanoi

    tohStep(numDisks);

    cout << endl;

    stack<int> sourceStack;
    stack<int> targetStack;
    stack<int> auxiliaryStack;

    for (int i = numDisks; i > 0; i--) {
        sourceStack.push(i);
    }

    cout << "Initial state:" << endl;
    displayTower(sourceStack, auxiliaryStack, targetStack);

    cout << "Moving disks from A to C:" << endl;

    move(
        numDisks,
        sourceStack,
        targetStack,
        auxiliaryStack
    );

    cout << "====================" << endl;

    return 0;
}
