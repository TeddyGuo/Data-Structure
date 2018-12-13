#include "prim.h"
#include "kruskal.h"
#include "dijkstra.h"

int main()
{
    cout << "Prim's algorithm" << endl;
    /* input
        11
        a b 2
        a d 9
        b c 3
        b d 8
        b e 7
        c e 4
        d e 5
        d f 10
        e f 12
        e g 11
        f g 13
        a
    */
    prim();
    cout << endl;
    cout << "Kruskal's algorithm" << endl;
    /* input
        9
        a b 7
        a c 6
        a d 1
        b c 8
        c d 5
        c e 3
        d e 4
        d f 5
        e f 2
    */
    kruskal();
    cout << endl;
    cout << "Dijkstra's" << endl;
    /* input
        9
        b a 4
        a c 2
        f c 9
        d b 15
        d f 5
        d g 23
        e b 17
        e g 11
        f g 13
        d
    */
    dijkstra();

    return 0;
}