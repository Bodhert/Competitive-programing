defmodule LinkedList do
  @opaque t :: tuple()

  @doc """
  Construct a new LinkedList
  """
  @spec new() :: t
  def new() do
    {nil, nil}
  end

  @doc """
  Push an item onto a LinkedList
  """
  @spec push(t, any()) :: t
  def push(list, elem) do
    {elem, list}
  end

  @doc """
  Calculate the length of a LinkedList
  """
  @spec length(t) :: non_neg_integer()
  def length({nil, nil}) do
    0
  end

  def length({head, tail}) do
    1 +  LinkedList.length(tail)
  end

  @doc """
  Determine if a LinkedList is empty
  """
  @spec empty?(t) :: boolean()
  def empty?(list) do
    list === {nil,nil}
  end

  @doc """
  Get the value of a head of the LinkedList
  """
  @spec peek(t) :: {:ok, any()} | {:error, :empty_list}
  def peek({nil,_}) do
    {:error, :empty_list}
  end

  def peek({elem, _}) do
    {:ok, elem}
  end

  @doc """
  Get tail of a LinkedList
  """
  @spec tail(t) :: {:ok, t} | {:error, :empty_list}
  def tail({_, nil}) do
    {:error, :empty_list}
  end

  def tail({_, list}) do
    {:ok, list}
  end


  @doc """
  Remove the head from a LinkedList
  """
  @spec pop(t) :: {:ok, any(), t} | {:error, :empty_list}
  def pop({nil,nil}) do
    {:error, :empty_list}
  end

  def pop({elem,tail}) do

    {:ok,elem,tail}
  end

  @doc """
  Construct a LinkedList from a stdlib List
  """
  @spec from_list(list()) :: t
  def from_list(list) do
    list
    |> Enum.reverse
    |> Enum.reduce(LinkedList.new(), fn(elem, acc) -> LinkedList.push(acc, elem) end)
    # Enum.reduce(list, LinkedList.new(),  &LinkedList.push(&2, &1))
  end

  @doc """
  Construct a stdlib List LinkedList from a LinkedList
  """
  @spec to_list(t) :: list()
  def to_list(list) do
    to_list([],list)
  end

  def to_list(acc,{nil, nil}) do
    acc
  end

  def to_list(acc,{head,tail}) do
    [head | to_list(acc,tail)]
  end

  @doc """
  Reverse a LinkedList
  """
  @spec reverse(t) :: t
  def reverse(list) do
    list
    |> to_list
    |> Enum.reverse
    |> from_list
  end
end
