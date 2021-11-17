defmodule KitchenCalculator do
  use TypeCheck
  @type! units() :: :milliliter | :fluid_ounce | :fluid_ounce | :tablespoon | :teaspoon | :cup
  @type! kitchen_units :: {units(), number}

  @cup_conversion 240
  @fluid_conversion 30
  @teaspoon_conversion 5
  @tablespoon_conversion 15

  @spec! get_volume({atom, number}) :: number
  def get_volume({_unit, number}), do: number

  @spec! to_milliliter(kitchen_units()) :: {:milliliter, number}
  def to_milliliter({:milliliter, num}), do: {:milliliter, num}
  def to_milliliter({:cup, num}), do: {:milliliter, num * @cup_conversion}
  def to_milliliter({:fluid_ounce, num}), do: {:milliliter, num * @fluid_conversion}
  def to_milliliter({:teaspoon, num}), do: {:milliliter, num * @teaspoon_conversion}
  def to_milliliter({:tablespoon, num}), do: {:milliliter, num * @tablespoon_conversion}

  @spec! from_milliliter({:milliliter, number}, units()) :: kitchen_units()
  def from_milliliter(milliliter_tuple, :milliliter),
    do: {:milliliter, get_volume(milliliter_tuple)}

  def from_milliliter(milliliter_tuple, :cup),
    do: {:cup, get_volume(milliliter_tuple) / @cup_conversion}

  def from_milliliter(milliliter_tuple, :fluid_ounce),
    do: {:fluid_ounce, get_volume(milliliter_tuple) / @fluid_conversion}

  def from_milliliter(milliliter_tuple, :teaspoon),
    do: {:teaspoon, get_volume(milliliter_tuple) / @teaspoon_conversion}

  def from_milliliter(milliliter_tuple, :tablespoon),
    do: {:tablespoon, get_volume(milliliter_tuple) / @tablespoon_conversion}

  @spec! convert(kitchen_units(), units()) :: kitchen_units()
  def convert(volume_pair, unit) do
    volume_pair
    |> to_milliliter
    |> from_milliliter(unit)
  end
end
