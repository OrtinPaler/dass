# frozen_string_literal: true

# helper for all app
module ApplicationHelper
  def full_title(page_title = '')
    base_title = 'Simply'
    if page_title.empty?
      base_title
    else
      "#{page_title}|#{base_title}"
    end
  end
end
