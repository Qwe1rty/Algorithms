//
// Created by Caleb Choi on 02/03/2019.
//

#include <iostream>
#include "AvlTree.h"

namespace
{
    struct Movable
    {
        explicit Movable(int);
        Movable(const Movable&);
        Movable(Movable&&);

        friend bool operator== (const Movable&, const Movable&);
        friend bool operator!= (const Movable&, const Movable&);
        friend bool operator<  (const Movable&, const Movable&);
        friend bool operator<= (const Movable&, const Movable&);
        friend bool operator>  (const Movable&, const Movable&);
        friend bool operator>= (const Movable&, const Movable&);
        friend std::ostream& operator<< (std::ostream&, const Movable&);

        std::unique_ptr<int> val_;
    };

    Movable::Movable(int i) : val_(std::make_unique<int>(i)) {}
    Movable::Movable(const Movable& src) : val_(std::make_unique<int>(*src.val_))
    { std::cout << "Movable copied: " << *val_ << std::endl; }
    Movable::Movable(Movable&& src) : val_(std::move(src.val_))
    { std::cout << "Movable moved: " << *val_ << std::endl; }

    bool operator== (const Movable& lhs, const Movable& rhs) { return *lhs.val_ == *rhs.val_; }
    bool operator!= (const Movable& lhs, const Movable& rhs) { return !(lhs == rhs); }
    bool operator<  (const Movable& lhs, const Movable& rhs) { return *lhs.val_ < *rhs.val_; }
    bool operator<= (const Movable& lhs, const Movable& rhs) { return (lhs < rhs) || (lhs == rhs); }
    bool operator>  (const Movable& lhs, const Movable& rhs) { return !(lhs <= rhs); }
    bool operator>= (const Movable& lhs, const Movable& rhs) { return !(lhs < rhs); }
    std::ostream& operator<< (std::ostream& os, const Movable& src)
    {
        os << *src.val_;
        return os;
    }
    
    struct Copyable
    {
        explicit Copyable(int);
        Copyable(const Copyable&);

        friend bool operator== (const Copyable&, const Copyable&);
        friend bool operator!= (const Copyable&, const Copyable&);
        friend bool operator<  (const Copyable&, const Copyable&);
        friend bool operator<= (const Copyable&, const Copyable&);
        friend bool operator>  (const Copyable&, const Copyable&);
        friend bool operator>= (const Copyable&, const Copyable&);
        friend std::ostream& operator<< (std::ostream&, const Copyable&);

        std::unique_ptr<int> val_;
    };

    Copyable::Copyable(int i) : val_(std::make_unique<int>(i)) {}
    Copyable::Copyable(const Copyable& src) : val_(std::make_unique<int>(*src.val_))
    { std::cout << "Copyable copied: " << *val_ << std::endl; }

    bool operator== (const Copyable& lhs, const Copyable& rhs) { return *lhs.val_ == *rhs.val_; }
    bool operator!= (const Copyable& lhs, const Copyable& rhs) { return !(lhs == rhs); }
    bool operator<  (const Copyable& lhs, const Copyable& rhs) { return *lhs.val_ < *rhs.val_; }
    bool operator<= (const Copyable& lhs, const Copyable& rhs) { return (lhs < rhs) || (lhs == rhs); }
    bool operator>  (const Copyable& lhs, const Copyable& rhs) { return !(lhs <= rhs); }
    bool operator>= (const Copyable& lhs, const Copyable& rhs) { return !(lhs < rhs); }
    std::ostream& operator<< (std::ostream& os, const Copyable& src)
    {
        os << *src.val_;
        return os;
    }
}

template<typename T>
void print_stats(const data::AvlTree<T>& tree)
{ std::cout << tree.empty() << ' ' << tree.height() << ' ' << tree.size() << std::endl; }

template<typename T>
void print_tree(const data::AvlTree<T>& tree)
{ std::cout << tree << std::endl; }

//int main()
//{
//    data::AvlTree<int> int_tree;
//    data::AvlTree<Movable> mov_tree;
//    data::AvlTree<Copyable> cpy_tree;
//
//    auto insert_int = [](data::AvlTree<int>& tree, int val)
//    {
//        tree.insert(val);
//        print_stats<int>(tree);
//        print_tree<int>(tree);
//    };
//    auto remove_int = [](data::AvlTree<int>& tree, int val)
//    {
//        tree.remove(val);
//        print_stats<int>(tree);
//        print_tree<int>(tree);
//    };
//    auto insert_mov = [&mov_tree](int val)
//    {
//        mov_tree.insert(Movable(val));
//        print_stats<Movable>(mov_tree);
//        print_tree<Movable>(mov_tree);
//    };
//    auto insert_cpy = [&cpy_tree](int val)
//    {
//        cpy_tree.insert(Copyable(val));
//        print_stats<Copyable>(cpy_tree);
//        print_tree<Copyable>(cpy_tree);
//    };
//
//    print_stats(int_tree);
//    insert_int(int_tree, 50);
//    insert_int(int_tree, 40);
//    insert_int(int_tree, 30); // Causes right rotation at depth 1 (root)
//    insert_int(int_tree, 20);
//    insert_int(int_tree, 10); // Causes right rotation at depth 2
//    insert_int(int_tree, 35); // Causes right-left rotation at depth 2
//    insert_int(int_tree, 70);
//    insert_int(int_tree, 80); // Causes left rotation at depth 3
//    insert_int(int_tree, 60); // Causes right-left rotation at depth 2
//    insert_int(int_tree, 15); // Causes left-right rotation at depth 2
//    insert_int(int_tree, 15); // Should do nothing
//    remove_int(int_tree, 15);
//    remove_int(int_tree, 20); // Causes left rotation at depth 1 (root)
//    remove_int(int_tree, 30); // Deleting node w/ two children, successor once removed
//    remove_int(int_tree, 35); // Deleting node w/ two children, successor immediate
//    remove_int(int_tree, 50);
//
//    std::cout << std::endl;
//
//    print_stats(mov_tree);
//    insert_mov(1);
//    insert_mov(2);
//    insert_mov(3);
//
//    std::cout << std::endl;
//
//    print_stats(cpy_tree);
//    insert_cpy(3);
//    insert_cpy(2);
//    insert_cpy(1);
//
//    std::cout << std::endl;
//
//    data::AvlTree<int> int_tree_copy = int_tree;
//    insert_int(int_tree_copy, 100);
//    insert_int(int_tree, 0);
//}