defmodule RobotSimulator do
  @doc """
  Create a Robot Simulator given an initial direction and position.

  Valid directions are: `:north`, `:east`, `:south`, `:west`
  """


  @spec create(direction :: atom, position :: {integer, integer}) :: any
  def create(direction \\ nil, position \\ nil) do
    cond do
      !direction and !position -> {:north, {0,0}}
      !validDirection?(direction)  ->  {:error, "invalid direction"}
      !validPosition?(position) ->  {:error, "invalid position"}
      validPosition?(position) and !direction -> {:north, position}
      true -> {direction, position}
    end
  end

  @spec validPosition?(position :: {integer, integer}) :: boolean() | nil
  def validPosition?(position) do
    is_tuple(position) and is_integer(elem(position,0)) and
    is_integer(elem(position,1)) and tuple_size(position) == 2
  end
  @spec validDirection?(direction::atom) :: boolean() | nil
  def validDirection?(direction) do
    direction == :north or direction == :east or
    direction == :south or direction == :west
  end

  @doc """
  Simulate the robot's movement given a string of instructions.

  Valid instructions are: "R" (turn right), "L", (turn left), and "A" (advance)
  """
  @spec simulate(robot :: any, instructions :: String.t()) :: any
  def simulate(robot, instructions) do
    cond do
      instructions == "" -> robot
      !isValidMove?(String.at(instructions,0)) ->
        robot = {:error, "invalid instruction"}
        robot
      true ->
        robot = makeMove(robot,String.at(instructions,0))
        simulate(robot, String.slice(instructions, 1..-1))
    end
  end

  def isValidMove?(instruction) do
    instruction == "L" or instruction == "R" or instruction == "A"
  end

  @spec makeMove(robot :: any, instruction :: String.t()) :: any
  def makeMove(robot, instruction) do
    cond do
      instruction == "L" and direction(robot) == :north
        -> create(:west, position(robot))
      instruction == "L" and direction(robot) == :west
        -> create(:south, position(robot))
      instruction == "L" and direction(robot) == :south
        -> create(:east, position(robot))
      instruction == "L" and direction(robot) == :east
        -> create(:north, position(robot))
      instruction == "R" and direction(robot) == :north
        -> create(:east, position(robot))
      instruction == "R" and direction(robot) == :east
        -> create(:south, position(robot))
      instruction == "R" and direction(robot) == :south
        -> create(:west, position(robot))
      instruction == "R" and direction(robot) == :west
        -> create(:north, position(robot))
      instruction == "A" and direction(robot) == :north
        ->
          {x,y} = position(robot)
          create(direction(robot),{x,y+1})
      instruction == "A" and direction(robot) == :south
        ->
          {x,y} = position(robot)
          create(direction(robot),{x,y-1})
      instruction == "A" and direction(robot) == :east
        ->
          {x,y} = position(robot)
          create(direction(robot),{x+1,y})
      instruction == "A" and direction(robot) == :west
        ->
          {x,y} = position(robot)
          create(direction(robot),{x-1,y})
    end
  end

  @doc """
  Return the robot's direction.

  Valid directions are: `:north`, `:east`, `:south`, `:west`
  """
  @spec direction(robot :: any) :: atom
  def direction(robot) do
    elem(robot,0)
  end

  @doc """
  Return the robot's position.
  """
  @spec position(robot :: any) :: {integer, integer}
  def position(robot) do
    elem(robot,1)
  end
end
