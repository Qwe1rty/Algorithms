//
// Created by Caleb Choi on 24/02/2019.
//

#ifndef CLION_AVL_TREE_H
#define CLION_AVL_TREE_H

#include <memory>
#include <ostream>

namespace data
{
    template<typename T> class AvlTree;
    template<typename T> bool operator== (const AvlTree<T>&, const AvlTree<T>&);
    template<typename T> bool operator!= (const AvlTree<T>&, const AvlTree<T>&);
    template<typename T> bool operator<  (const AvlTree<T>&, const AvlTree<T>&);
    template<typename T> bool operator<= (const AvlTree<T>&, const AvlTree<T>&);
    template<typename T> bool operator>  (const AvlTree<T>&, const AvlTree<T>&);
    template<typename T> bool operator>= (const AvlTree<T>&, const AvlTree<T>&);
    template<typename T> std::ostream& operator<< (std::ostream&, const AvlTree<T>&);

    template<typename T>
    class AvlTree final
    {
    public:

        /* Aliases */
        using value_type        = T;
        using pointer           = value_type*;
        using reference         = value_type&;
        using const_reference   = const value_type&;
        using move_reference    = value_type&&;
        using size_type         = int; // https://www.aristeia.com/Papers/C++ReportColumns/sep95.pdf

        /* Special member functions */
        AvlTree()  = default;
        ~AvlTree() = default;
        AvlTree(const AvlTree<T>&);
        AvlTree(AvlTree<T>&&) noexcept;
        AvlTree<T>& operator= (const AvlTree<T>&);
        AvlTree<T>& operator= (AvlTree<T>&&) noexcept;

        /* Interface functions */
        size_type size() const noexcept;
        size_type height() const noexcept;
        bool contains(const T&) const noexcept;
        bool empty() const noexcept;
        void remove(const T&);
        void remove(T&&);
        void insert(const T&);
        void insert(T&&);
        template<typename...Args> void emplace(Args&&...);

        /* Relational operator overloads */
        // https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class
        // http://web.mst.edu/~nmjxv3/articles/templates.html
        friend bool operator== <T>(const AvlTree<T>& lhs, const AvlTree<T>& rhs);
        friend bool operator!= <T>(const AvlTree<T>& lhs, const AvlTree<T>& rhs);
        friend bool operator<  <T>(const AvlTree<T>& lhs, const AvlTree<T>& rhs);
        friend bool operator<= <T>(const AvlTree<T>& lhs, const AvlTree<T>& rhs);
        friend bool operator>  <T>(const AvlTree<T>& lhs, const AvlTree<T>& rhs);
        friend bool operator>= <T>(const AvlTree<T>& lhs, const AvlTree<T>& rhs);

        /* Other operator overloads */
        friend std::ostream& operator<< <T>(std::ostream&, const AvlTree<T>&);

    private:

        /* Node struct */
        class Node
        {
        public:

            /* Special member functions (Node) */
            Node() = delete;
            ~Node() = default;
            Node(const Node&);
            Node(Node&&) noexcept;
            explicit Node(const T&);
            explicit Node(T&&);
            Node& operator= (const Node&);
            Node& operator= (Node&&) noexcept;

            /* Interface functions (Node) */
            static void print(std::ostream&, const std::unique_ptr<Node>&, const int = 0);
            static size_type get_size(const std::unique_ptr<Node>&) noexcept;
            static size_type get_height(const std::unique_ptr<Node>&) noexcept;
            static Node* find(const T&) noexcept;
            static bool contains(const T&) noexcept;
            template<typename V>
            static std::unique_ptr<Node> insert(V&&, std::unique_ptr<Node>);
            template<typename V>
            static std::unique_ptr<Node> remove(V&&, std::unique_ptr<Node>);

        private:

            /* AVL functions */
            static std::unique_ptr<Node> rebalance(std::unique_ptr<Node>);
            static std::unique_ptr<Node> rotate_left(std::unique_ptr<Node>);
            static std::unique_ptr<Node> rotate_right(std::unique_ptr<Node>);
            static std::unique_ptr<Node> successor(Node*);
            static int delta(const std::unique_ptr<Node>&) noexcept;
            static void update_stats(Node*);

            /* Fields (Node) */
            Node* parent_ = nullptr;
            std::unique_ptr<Node> left_;
            std::unique_ptr<Node> right_;
            std::unique_ptr<T> val_;
            size_type size_ = 1;
            size_type height_ = 1;
        };

        /* Fields */
        std::unique_ptr<Node> head_;
    };
}

#include "AvlTree.tpp"

#endif //CLION_AVL_TREE_H
