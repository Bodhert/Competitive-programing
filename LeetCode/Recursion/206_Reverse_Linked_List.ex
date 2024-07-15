# Definition for singly-linked list.
#
defmodule ListNode do
  @type t :: %__MODULE__{
          val: integer,
          next: ListNode.t() | nil
        }
  defstruct val: 0, next: nil
end

defmodule Solution do
  @spec reverse_list(head :: ListNode.t | nil) :: ListNode.t | nil

  def reverse_list(nil) do
    nil
  end

  def reverse_list(head) do
    do_reverse(head, %ListNode{val: head.val, next: nil})
  end

  def do_reverse(nil, _acc) do
    nil
  end

  def do_reverse(%ListNode{val: val, next: nil}, acc) do
    %ListNode{acc | val: val}
  end

  def do_reverse(%ListNode{val: val, next: next}, acc) do
   new_node = %ListNode{val: val, next: acc.next}
   acc = %ListNode{acc | next: new_node}
   do_reverse(next, acc)
  end

end
