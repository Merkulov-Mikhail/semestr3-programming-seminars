#include <memory>
#include <iostream>


template <typename T>
class ForwardList {
    struct Node {
        T value;
        std::unique_ptr<Node> next;

        Node (T v, std::unique_ptr<Node> n): value(v), next(std::move(n)) {}
    };

    std::unique_ptr<Node> head_;
    Node* tail_;
public:
    ForwardList(): head_(nullptr), tail_(nullptr) {}

    void print() {
        for (auto cur = head_.get(); cur != nullptr; cur = cur->next.get())
            std::cout << cur->value << " ";
        std::cout << "\n";
    }

    void push_front(T elem) {
        auto newHead = std::make_unique<Node>(elem, std::move(head_));
        head_ = std::move(newHead);

        if (tail_ == nullptr)
            tail_ = head_.get();
    }

    void push_back(T elem) {
        auto newTail = std::make_unique<Node>(elem, nullptr);
        Node* addr = newTail.get();

        if (tail_ != nullptr) {
            tail_->next = std::move(newTail);
        }
        else {
            head_ = std::move(newTail);
        }
        tail_ = addr;
    }

    std::unique_ptr<Node> pop_front() {
        if (head_ == nullptr)
            return nullptr;

        auto to_ret = std::move(head_);
        head_ = std::move(to_ret->next);

        if (head_ == nullptr)
            tail_ = nullptr;

        return to_ret;
    }

    void clear() {
        for (; head_ != nullptr; head_ = std::move(head_->next));
        tail_ = nullptr;
    }

    template <typename F>
    void foreach(F f) {
        for (auto tmp = head_.get(); tmp != nullptr; tmp = tmp->next.get())
            f(tmp);
    }

    void swap(ForwardList& fl) {
        std::swap(fl.head_, head_);
        std::swap(fl.tail_, tail_);
    }

    ForwardList<T> copy() {
        ForwardList<T> fl{};
        for (auto tmp = head_.get(); tmp != nullptr; tmp = tmp->next.get())
            fl.push_back(tmp->value);
        return fl;
    }
};


int main() {
    ForwardList<int> a{};
    a.push_front(2);
    a.push_front(2);
    a.push_back(23);
    ForwardList<int> b{};
    b.push_front(15);

    a.swap(b);

    a.print();
    b.print();

    ForwardList<int> d = a.copy();
    d.print();
}

